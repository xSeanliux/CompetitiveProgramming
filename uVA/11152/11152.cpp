#include <iostream>
#include <math.h>
#define PI acos(-1)
using namespace std;

double a, b, c;

int main(){
    while(cin >> a >> b >> c){
        double p = (a + b + c)/2;
        double S = sqrt(p*(p-a)*(p-b)*(p-c));
        double iR = S/p;
        double oR = a*b*c/4/S;
        printf("%.4f %.4f %.4f\n", oR*oR*PI - S, S - iR*iR*PI, iR*iR*PI);
    }
}
