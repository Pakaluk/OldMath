/*
 
 So the point of this program is to do polynomial operations quickly for you.
 
 One way to represent a polynomial of the form nx^m ... cx^2 + bx + a
 is with a vector, with each index storing the constant of the term
 raised to the power of that index. Example: 3x^4 + x^2 - 2x + 1 can
 be rewritten as 1x^0 - 2x^1 + 1x^2 + 0x^3 + 3x^4 which can be further
 simplified as [1, -2, 1, 0, 3] with the indices as the powers of x.
 
 Multiplication, addition, subtraction, integration, and derivation
 become simple with this system, and also applicable to polynomials
 of any size or power.
 
 But what kind of user-friendly system asks the user to re-arrange
 the polynomial before entering it? So I made a text interpreter,
 that can take a string of the form nx^m ... cx^2 + bx + a and turn
 it into [a, b, c ... n]. I also made a function to do the reverse.
 So now the user can enter their polynomial with no edits in text
 form and perform various operations on it, and have the output be
 in the same form as the input.
 
 I also made a simple function to find the y value at any x for any
 polynomial. This means that, combined with the integrate function,
 definite integrals can be evaluated from any a to any b. Furthermore,
 the definite integral function outputs not in floating point form but
 in integer form, and with a few binary operations the numerator and
 denominator of the answer can be obtained from this one integer. This
 means that all output will be in the form of a fraction, not a floating
 point number.
 
 Copyright / Nicholas Pakaluk / 10.05.2020
 
 */

#include <cmath>
#include <array>
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
#define LOG(x) std::cout << x << std::endl;

// Converts a decimal number to a fraction with
// accuracy loss for high or irratoinal numbers
// (yes I did come up with this myself)
string fraction(float num){
    float modFin, temp = num;
    int sign, mult = 0;
    sign = num >= 0 ? 1 : -1;
    temp *= sign;
    do{
        mult++;
        modFin = temp * static_cast<float>(mult);
        if(mult > 9999){
            break;
        }
    }
    while((modFin - (floor(modFin))) > 0.00001);
    if(mult > 1){
        return to_string(static_cast<int>(sign * modFin)) + "/" + to_string(mult);
    }
    return to_string(static_cast<int>(sign * modFin));
};

// this overloaded ask function is extremely useful
void ask(string question, float &answer){
    cout << question << " ";
    cin >> answer;
};
void ask(string question, int &answer){
    cout << question << " ";
    cin >> answer;
};
void ask(string question, char &answer){
    cout << question << " ";
    cin >> answer;
};
void ask(string question, string &answer){
    cout << question << " ";
    cin >> answer;
}

// polynomial operations
vector<float> polyMult(vector<float> poly1, vector<float> poly2){
    // multiplies two polynomials
    vector<float> newPoly (poly1.size() + poly2.size() - 1, 0);
    int x1, x2;
    for(x1 = 0; x1 < poly1.size(); x1++){
        for(x2 = 0; x2 < poly2.size(); x2++){
            if(!newPoly[x1 + x2]){
                newPoly[x1 + x2] = poly1[x1] * poly2[x2];
            }
            else{
                newPoly[x1 + x2] += poly1[x1] * poly2[x2];
            }
        }
    }
    return newPoly;
};
vector<float> polyAdd(vector<float> poly1, vector<float> poly2){
    // adds two polynomials
    vector<float> newPoly(max(poly1.size(), poly2.size()), 0);
    for(int i = 0; i < max(poly1.size(), poly2.size()); i++){
        if(!poly1[i] && poly2[i]){
            newPoly[i] = poly2[i];
        }
        else if(poly1[i] && !poly2[i]){
            newPoly[i] = poly1[i];
        }
        else{
            newPoly[i] = poly1[i] + poly2[i];
        }
    }
    return newPoly;
}
vector<float> polySub(vector<float> poly1, vector<float> poly2){
    // subtracts two polynomials
    vector<float> newPoly (max(poly1.size(), poly2.size()), 0);
    for(int i = 0; i < max(poly1.size(), poly2.size()); i++){
        if(!poly1[i] && poly2[i]){
            newPoly[i] = -poly2[i];
        }
        else if(poly1[i] && !poly2[i]){
            newPoly[i] = poly1[i];
        }
        else{
            newPoly[i] = poly1[i] - poly2[i];
        }
    }
    return newPoly;
}
vector<float> polyPow(vector<float> poly, int power){
    // raises polynomial to a positive power
    vector<float> newPoly(poly);
    for(int i = 0; i < power - 1; i++){
        newPoly = polyMult(newPoly, poly);
    }
    return newPoly;
}
vector<float> polyInteg(vector <float> poly){
    // integrates polynomial with reverse power rule
    vector<float> newPoly (poly.size() + 1, 0);
    for(int i = 0; i < poly.size(); i++){
        newPoly[i + 1] = poly[i] / (i + 1);
    }
    return newPoly;
}
vector<float> polyDeriv(vector<float> poly){
    // derives polynomials with power rule
    vector<float> newPoly (poly.size() - 1);
    for(int i = 1; i < poly.size(); i++){
        newPoly[i - 1] = poly[i] * i;
    }
    return newPoly;
}
float polyAt(vector<float> poly, float x){
    // returns the value of y at x
    float value = 0;
    for(int i = 0; i < poly.size(); i++){
        value += poly[i] * pow(x, i);
    }
    return value;
}
vector<float> polyLine(vector<float> poly, float x){
    // calculates line tangent to curve at x
    vector<float> deriv = polyDeriv(poly);
    float m = polyAt(deriv, x),
          y = polyAt(poly, x);
    if(m){
        return vector<float> {y - m * x, m};
    }
    else{
        return vector<float> {y};
    }
}
vector<float> polyParse(string text){
    // The most complex function here, I won't bother to explain.
    if(text.length() == 0){
        return vector<float> {0.0};
    }
    string txt = "";
    int constants = 1;
    vector<float> poly;
    for(int i = 0; i < text.length(); i++){
        if(text[i] == ' '){
            continue;
        }
        if(i){
            if(text[i] == '+'){
                constants ++;
            }
            else if(text[i] == '-'){
                constants ++;
                txt += "+-";
                continue;
            }
        }
        txt += text[i];
    }
    vector<string> txts;
    for(int i = 0; i < constants; i++){
        int index = 0;
        for(int i = static_cast<int>(txt.length()) - 1; i >= 0; i--){
            if(txt[i] == '+'){
                index = i;
            }
        }
        if(index){
            txts.push_back(txt.substr(0, index));
            txt.replace(0, index + 1, "");
        }
        else{
            txts.push_back(txt);
            break;
        }
    }
    for(int i = 0; i < txts.size(); i++){
        int ix = -1, ir = -1;
        string seg;
        string cs, ps;
        float csd, psd;
        seg.append(txts[i]);
        for(int j = static_cast<int>(seg.length()) - 1; j >= 0; j--){
            if(tolower(seg[j]) == 'x'){
                ix = j;
            }
            else if(seg[j] == '^'){
                ir = j;
            }
        }
        if(ix < 0){
            if(poly.size() < 1){
                poly.push_back(stof(seg));
            }
            else{
                poly[0] += stof(seg);
            }
            continue;
        }
        cs = seg.substr(0, ix);
        if(cs == ""){
            cs = "1";
        }
        else if(cs == "-"){
            cs = "-1";
        }
        if(ir < 0){
            ps = seg.substr(ix + 1, -1);
        }
        else{
            ps = seg.substr(ir + 1, -1);
        }
        if(ps == ""){
            ps = "1";
        }
        else if(ps == "-"){
            ps = "-1";
        }
        csd = stof(cs);
        psd = abs(stof(ps));
        if(poly.size() < static_cast<int>(psd) + 1){
            do{
                poly.push_back(0);
            }
            while(poly.size() < static_cast<int>(psd));
            poly.push_back(csd);
        }
        else{
            poly[static_cast<int>(psd)] += csd;
        }
    }
    return poly;
};
float polyEval(vector<float> poly, float a, float b){
    // indefinite integral
    float fin = 0;
    vector<float> integ = polyInteg(poly);
    for(int i = 0; i < integ.size(); i++){
        fin += integ[i] * pow(b, i);
        fin -= integ[i] * pow(a, i);
    }
    return fin;
}
string polyReverse(vector<float> poly){
    // also not gonna explain
    if(poly.size() == 1 && poly[0] == 0){
        return "0";
    }
    string str = "";
    for(int i = static_cast<int>(poly.size()) - 1; i >= 0; i--){
        string temp = "";
        if(poly[i]){
            if(poly[i] > 0 && i != poly.size() - 1){
                temp += " + ";
            }
            else if(poly[i] < 0 && i != poly.size() - 1){
                temp += " - ";
            }
            if(poly[i] < 0 && i == poly.size() - 1){
                temp += "-";
            }
            if(!i || abs(poly[i]) != 1){
                string otemp = to_string(abs(poly[i]));
                while(otemp[otemp.length() - 1] == '0' || otemp[otemp.length() - 1] == '.'){
                    if(otemp[otemp.length() - 1] == '.'){
                        otemp.replace(otemp.length() - 1, otemp.length(), "");
                        break;
                    }
                    else{
                        otemp.replace(otemp.length() - 1, otemp.length(), "");
                    }
                }
                temp += otemp;
            }
            if(i > 0){
                if(i > 1){
                    temp += "x^" + to_string(i);
                }
                else{
                    temp += "x";
                }
            }
            str += temp;
        }
    }
    return str;
}

// scene help
void polyTest(vector<float> &pol1, vector<float> &pol2, string &pol1txt, string &pol2txt){
    if(pol1.size() == 0 && pol2.size() == 0){
        cout << "\nEnter your first polynomial ";
        cout << "in this form: 5x^4 - 3x^2 + 1\n";
        cout << "Use no fractions, and no variables besides x:\n";
        cin.ignore();
        getline(cin, pol1txt);
        cout << "\nEnter your second polynomial ";
        cout << "in this form: 5x^4 - 3x^2 + 1\n";
        cout << "Use no fractions, and no variables besides x:\n";
        getline(cin, pol2txt);
        pol1 = polyParse(pol1txt);
        pol2 = polyParse(pol2txt);
    }
    cout << "\nCurrent polynomial 1: " << pol1txt << endl;
    cout << "Current polynomial 2: " << pol2txt << "\n" << endl;
}
void menuTest(int &scn){
    do{
        cout << "Would you like to return to the menu or quit the application?\n";
        ask("(enter 0 to return to the menu, or 11 to quit):", scn);
    }
    while(scn != 0 && scn != 11);
}

// interactivity
int main(){
    float a, b, x, y;
    int power, scene = 0, dir = 0;
    string poly1Text = "", poly2Text = "", integText = "", derivText = "", whole;
    vector<float> polynomial1, polynomial2, integ, deriv;
    
    do{
        switch (scene){
            // main menu
            case 0:
                cout << "This is a general purpose polynomial calculator." << endl;;
                cout << "The options are as follows:" << endl;
                cout << "1. Multiply polynomials" << endl;
                cout << "2. Add polynomials" << endl;
                cout << "3. Subtract polynomials" << endl;
                cout << "4. Raise a polynomial to a Power" << endl;
                cout << "5. Display the integral of a polynomial" << endl;
                cout << "6. Find derivative of a polynomial" << endl;
                cout << "7. Evaluate the definite integral" << endl;
                cout << "8. Evaluate a polynomial at x" << endl;
                cout << "9. Change polynomials" << endl;
                cout << "10. Find the line tangent to a polynomial at x" << endl;
                cout << "11. Quit Application" << endl;
                do{
                    ask("Enter the number of your choice (1 - 11):", scene);
                }
                while(scene > 11 || scene < 1);
            break;
            
            // multiplication
            case 1:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                do{
                    ask("Would you like to multiply 1 by 2 or 2 by 1? (1 and 2 respectively)", dir);
                }
                while(dir > 2 || dir < 1);
                switch (dir){
                    case 1:
                        polynomial1 = polyMult(polynomial1, polynomial2);
                        poly1Text = polyReverse(polynomial1);
                        cout << "Your new polynomial 1: " << poly1Text << endl;
                    break;
                    case 2:
                        polynomial2 = polyMult(polynomial2, polynomial1);
                        poly2Text = polyReverse(polynomial2);
                        cout << "Your new polynomial 2: " << poly2Text << endl;
                    break;
                };
                menuTest(scene);
            break;
            
            // addition
            case 2:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                do{
                    ask("Would you like to add 2 to 1 or 1 to 2? (1 and 2 respectively)", dir);
                }
                while(dir > 2 || dir < 1);
                switch (dir){
                    case 1:
                        polynomial1 = polyAdd(polynomial1, polynomial2);
                        poly1Text = polyReverse(polynomial1);
                        cout << "Your new polynomial 1: " << poly1Text << endl;
                    break;
                    case 2:
                        polynomial2 = polyAdd(polynomial2, polynomial1);
                        poly2Text = polyReverse(polynomial2);
                        cout << "Your new polynomial 2: " << poly2Text << endl;
                    break;
                };
                menuTest(scene);
            break;
            
            // subtraction
            case 3:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                do{
                    ask("Would you like to subtract 2 from 1 or 1 from 2? (1 and 2 respectively)", dir);
                }
                while(dir > 2 || dir < 1);
                switch (dir){
                    case 1:
                        polynomial1 = polySub(polynomial1, polynomial2);
                        poly1Text = polyReverse(polynomial1);
                        cout << "Your new polynomial 1: " << poly1Text << endl;
                    break;
                    case 2:
                        polynomial2 = polySub(polynomial2, polynomial1);
                        poly2Text = polyReverse(polynomial2);
                        cout << "Your new polynomial 2: " << poly2Text << endl;
                    break;
                };
                menuTest(scene);
            break;
            
            // exponential
            case 4:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                do{
                    ask("Would you like to raise polynomial 1 or 2 to a power?", dir);
                }
                while(dir > 2 || dir < 1);
                switch (dir){
                    case 1:
                        do{
                            ask("What power would you like to raise polynomial 1 to?", power);
                        }
                        while(power < 0);
                        polynomial1 = polyPow(polynomial1, power);
                        poly1Text = polyReverse(polynomial1);
                        cout << "Your new polynomial 1: " << poly1Text << endl;
                    break;
                    case 2:
                        do{
                            ask("What power would you like to raise polynomial 1 to?", power);
                        }
                        while(power < 0);
                        polynomial2 = polyPow(polynomial2, power);
                        poly2Text = polyReverse(polynomial2);
                        cout << "Your new polynomial 2: " << poly2Text << endl;
                    break;
                };
                menuTest(scene);
            break;
            
            // indefinite integration
            case 5:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                do{
                    ask("Would you like to print the indefinite integral of polynomial 1 or 2?", dir);
                }
                while(dir > 2 || dir < 1);
                switch (dir){
                    case 1:
                        integ = polyInteg(polynomial1);
                        integText = polyReverse(integ);
                        cout << "The integral of " << poly1Text << " is: " << integText << " + C\n";
                        integ.clear();
                        integText = "";
                    break;
                    case 2:
                        integ = polyInteg(polynomial2);
                        integText = polyReverse(integ);
                        cout << "The integral of " << poly2Text << " is: " << integText << " + C\n";
                        integ.clear();
                        integText = "";
                    break;
                };
                menuTest(scene);
            break;
            
            // derivation
            case 6:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                cout << "Would you like to:\n" << endl;
                cout << "1. Print the derivative of polynomial 1" << endl;
                cout << "2. Print the derivative of polynomial 2" << endl;
                cout << "3. Take the derivative of polynomial 1" << endl;
                cout << "4. Take the derivative of polynomial 2" << endl;
                do{
                    ask("Enter the number of your choice (1 - 4):", dir);
                }
                while(dir > 4 || dir < 1);
                
                switch (dir){
                    case 1:
                        deriv = polyDeriv(polynomial1);
                        derivText = polyReverse(integ);
                        cout << "The derivative of " << poly1Text << " is: " << derivText << endl;
                        deriv.clear();
                        derivText = "";
                    break;
                    case 2:
                        deriv = polyDeriv(polynomial2);
                        derivText = polyReverse(integ);
                        cout << "The derivative of " << poly2Text << " is: " << derivText << endl;
                        deriv.clear();
                        derivText = "";
                    break;
                    case 3:
                        polynomial1 = polyDeriv(polynomial1);
                        poly1Text = polyReverse(polynomial1);
                        cout << "Your new polynomial 1: " << poly1Text << endl;
                    break;
                    case 4:
                        polynomial2 = polyDeriv(polynomial2);
                        poly2Text = polyReverse(polynomial2);
                        cout << "Your new polynomial 2: " << poly2Text << endl;
                    break;
                };
                menuTest(scene);
            break;
            
            // definite integration
            case 7:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                cout << "Would you like to:" << endl;
                cout << "1. Print the integral of polynomial 1 from a to b" << endl;
                cout << "2. Print the integral of polynomial 2 from a to b" << endl;
                do{
                    ask("Enter the number of your choice (1 - 2):", dir);
                }
                while(dir > 4 || dir < 1);
                switch (dir){
                    case 1:
                        ask("Enter the lower bound (a):", a);
                        ask("Enter the upper bound (b):", b);
                        whole = fraction(polyEval(polynomial1, a, b));
                        cout << "The integral of " << poly1Text << " from ";
                        cout << a << " to " << b << " is: " << whole << endl;
                    break;
                    case 2:
                        ask("Enter the lower bound (a):", a);
                        ask("Enter the upper bound (b):", b);
                        whole = fraction(polyEval(polynomial2, a, b));
                        cout << "The integral of " << poly2Text << " from ";
                        cout << a << " to " << b << " is: " << whole << endl;
                    break;
                };
                menuTest(scene);
            break;
            
            // evaluation at x
            case 8:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                do{
                    ask("Which polynomial would you like to plug-in x to? (1 - 2)", dir);
                }
                while(dir > 4 || dir < 1);
                switch (dir){
                    case 1:
                        ask("What is your x?", x);
                        y = polyAt(polynomial1, x);
                        cout << poly1Text << " evaluated at " << x << " equals " << y << endl;
                    break;
                    case 2:
                        ask("What is your x?", x);
                        y = polyAt(polynomial2, x);
                        cout << poly2Text << " evaluated at " << x << " equals " << y << endl;
                    break;
                };
                menuTest(scene);
            break;
                
            // change polynomials
            case 9:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                cout << "Would you like to:" << endl;
                cout << "1. Change polynomial 1" << endl;
                cout << "2. Change polynomial 2" << endl;
                cout << "3. Change both polynomials" << endl;
                do{
                    ask("Enter the number of your choice (1 - 3):", dir);
                }
                while(dir > 3 || dir < 1);
                switch (dir){
                    case 1:
                        cout << "\nEnter the text of your new polynomial 1:" << endl;
                        cin.ignore();
                        getline(cin, poly1Text);
                        polynomial1 = polyParse(poly1Text);
                        cout << "Your new polynomial 1: " << poly1Text << endl;
                    break;
                    case 2:
                        cout << "\nEnter the text of your new polynomial 2:" << endl;
                        cin.ignore();
                        getline(cin, poly2Text);
                        polynomial2 = polyParse(poly2Text);
                        cout << "Your new polynomial 2: " << poly2Text << endl;
                    break;
                    case 3:
                        cin.ignore();
                        cout << "\nEnter the text of your new polynomial 1:" << endl;
                        getline(cin, poly1Text);
                        cout << "\nEnter the text of your new polynomial 2:" << endl;
                        getline(cin, poly2Text);
                        polynomial1 = polyParse(poly1Text);
                        polynomial2 = polyParse(poly2Text);
                        cout << "Your new polynomial 1: " << poly1Text << endl;
                        cout << "Your new polynomial 2: " << poly2Text << endl;
                    break;
                };
                menuTest(scene);
            break;
            
            // multiplication
            case 10:
                polyTest(polynomial1, polynomial2, poly1Text, poly2Text);
                do{
                    ask("Would you like to find the line tangent to 1 or 2?", dir);
                }
                while(dir > 2 || dir < 1);
                switch (dir){
                    case 1:
                        cout << "At what x would you like to find the tangent line? ";
                        cin >> x;
                        cout << "The equation of the line tangent to " << poly1Text << " at " << x << " is:\n";
                        cout << "y = " << polyReverse(polyLine(polynomial1, x)) << endl;
                    break;
                    case 2:
                        cout << "At what x would you like to find the tangent line? ";
                        cin >> x;
                        cout << "The equation of the line tangent to " << poly2Text <<  " at " << x << " is:\n";
                        cout << "y = " << polyReverse(polyLine(polynomial2, x)) << endl;
                    break;
                };
                menuTest(scene);
            break;
        };
    } while(scene != 11);
    cout << "\n\nprogram terminated\n\n\n";
    return 0;
}

