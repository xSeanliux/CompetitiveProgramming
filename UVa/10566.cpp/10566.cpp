#include <iostream>
#include <math.h>
using namespace std;

double a, b, c;

bool getVal(double l){
    return (sqrt(a*a*b*b - a*a*l*l - b*b*l*l + l*l*l*l));
}

int main(){
    while(cin >> a >> b >> c){
        double U = min(a, b), L = 0, M = (U + L) / 2;
        while(U - L > 1e-9)
    }
}
