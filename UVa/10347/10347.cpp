#include <iostream>
#include <math.h>
using namespace std;

double ma, mb, mc;

double area(double a, double b, double c){
    double s = (a + b + c)/2;
    if(s*(s-a)*(s-b)*(s-c) < 0) return -1;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main(){
    while(cin >> ma >> mb >> mc){
        double ans = area(ma*2/3, mb*2/3, mc*2/3);
        if(ans <= 0) printf("-1.000\n");
        else printf("%.3lf\n", 3*area(ma*2/3, mb*2/3, mc*2/3));
    }
}
