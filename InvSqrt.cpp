// a fast algorithm for computing the inverse square root of a number
#include <cmath>

#include <iostream>
using namespace std;

float fastInvSqrt(float x){
    long i;
    float x2, y;
    const float th = 1.5F;

    x2 = x * 0.5F;
    y  = x;
    i  = * ( long * ) &y;
    i  = 0x5f3759df - ( i >> 1 ); // magic
    y  = * ( float * ) &i;
    y  *= ( th - x2 * y * y ); // repeat to increase accuracey

    return y;
}

float slowInvSqrt(float x){
    return 1.0F/sqrt(x);
};

int main(){
    float f;
    for(int i = 0; i < 100000000; i++){
        f = slowInvSqrt(static_cast<float>(i));
    }
    
    return 0;
}