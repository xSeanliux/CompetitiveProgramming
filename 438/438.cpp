#include <iostream>
#include <math.h>
using namespace std;

double a1, b1, a2, b2, a3, b3;

double dis(double a, double b, double c, double d){
    return (sqrt(pow(a - c, 2) + pow(b - d ,2)));
}

int main(){
    while(cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3){
        double a = dis(a1, b1, a2, b2);
        double b = dis(a1, b1, a3, b3);
        double c = dis(a3, b3, a2, b2);
        double s = (a + b + c)/2;
        double A = sqrt(s*(s-a)*(s-b)*(s-c));
        double D = a*b*c/A/4;
        double PI = 3.141592653589793;
        double dia = PI * D * 2;
        dia = round(dia * 100)/100;
        printf("%.2f\n", dia);
    }
}
