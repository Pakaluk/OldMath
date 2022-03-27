//
//  main.cpp
//  VecLib
//
//  Created by Nicholas Pakaluk on 7/5/21.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "math.h"
vec4 floor(vec4 v){
    return vec4(std::floor(v.x), std::floor(v.y), std::floor(v.z), std::floor(v.w));
}
vec4 round(vec4 v){
    return vec4(std::round(v.x), std::round(v.y), std::round(v.z), std::round(v.w));
}
vec4 min(vec4 v, double m){
    return vec4(std::min(v.x, m), std::min(v.y, m), std::min(v.z, m), std::min(v.w, m));
}
int main(int argc, const char * argv[]) {
    //arbitrary vector testing
    /*vector<int> test(0);
    
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(-40);
    
    test[3] = 4;
    
    vector<int> chest(test);
    chest *= test;// * test;
    
    vector<int> best(test + chest);
    //best.print();
    //best.reserve(5);
    
    test.print();
    chest.print();
    best.print();*/
    
    
    // fibonacci sequence
    /*mat2 test = mat2(vec2(0, 1), vec2(1, 1));
    mat2 fib = test;
    
    fib.print();
    for(int i = 0; i < 7; i++){
        fib = fib * test * test;
        fib.print();
    }*/
    
    
    
    /*      Market    |      painting | resurfacing | cleaning | carpet cleaning
    vec4 Austin       = vec4(    4,          1,           6,           1        );
    vec4 Jacksonville = vec4(    2,          3,           3,           0        );
    vec4 Tampa        = vec4(    1,          0,           1,           0        );*/
    
    // Market | painting | resurfacing| cleaning | carpet cleaning
    vec4 Austin       = vec4(4, 1, 6, 1);
    vec4 Jacksonville = vec4(2, 3, 3, 0);
    vec4 Tampa        = vec4(1, 0, 1, 0);

    Austin *= 2.0 / 3.0;
    Jacksonville *= 2.0 / 3.0;
    Tampa *= 2.0 / 3.0;
    
    
    Austin += vec4(0, 0, 4.0 / 300.0, 0) * 49;
    Austin += vec4(0, 0, 5.0 / 300.0, 0) * 49;
    Austin += vec4(0, 0, 3.0 / 300.0, 0) * 47;
    Tampa  += vec4(0, 2.0 / 100.0, 1.0 / 300.0, 0) * 122;
    Austin += vec4(2.0 / 200.0, 2.0 / 100.0, 3.0 / 300, 0) * 120;
    
    
    Austin +=       min(floor(vec4(2,  0,  0,  0) / 6), 2.0);
    Tampa +=        min(floor(vec4(2,  0,  0,  0) / 6), 2.0);
    Jacksonville += min(floor(vec4(3,  0,  0,  0) / 6), 2.0);
    Jacksonville += min(floor(vec4(1,  10, 1,  1) / 6), 2.0);
    Austin +=       min(floor(vec4(43, 13, 1,  2) / 6), 2.0);
    Tampa +=        min(floor(vec4(0,  0,  6,  0) / 6), 2.0);
    Tampa +=        min(floor(vec4(4,  0,  0,  0) / 6), 2.0);
    Austin +=       min(floor(vec4(0,  0,  13, 0) / 6), 2.0);
    Austin +=       min(floor(vec4(0,  0,  6,  0) / 6), 2.0);
    Austin +=       min(floor(vec4(0,  11, 29, 30)/ 6), 2.0);
    Jacksonville += min(floor(vec4(0,  0,  7,  0) / 6), 2.0);
    Jacksonville += min(floor(vec4(0,  0,  6,  0) / 6), 2.0);
    Tampa +=        min(floor(vec4(0,  0,  8,  0) / 6), 2.0);
    Jacksonville += min(floor(vec4(0,  10, 4,  0) / 6), 2.0);
    Tampa +=        min(floor(vec4(0,  10, 0,  0) / 6), 2.0);
    Austin +=       min(floor(vec4(5,  6,  0,  0) / 6), 2.0);
    
    
    floor(Austin).print();
    floor(Jacksonville).print();
    floor(Tampa).print();
    
    
    
    return 0;
}
