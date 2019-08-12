#include <iostream>
#include <math.h>
#include <cstdio>
#include <iomanip>
using namespace std;

const double pi = 3.1415926535897;

int gcd(int a, int b){
    while(a != b){
        if(a >= b) a -= b;
        else b -= a;
    }
    return a;
}

int main(){
    cout << fixed << setprecision(7);
    double n,m,d,result;
    for(n = 3; n <= 100; n++){
        for(m = 1; m <= 100; m++){
            d = 360/n;
            d = 180 - d;
            d /= 2;
            result = cos(d*pi/180.0);
            printf("%d %d %.3f\n", (int)round(n), (int)round(m), m*result/(1-result));
        }
    }
}
