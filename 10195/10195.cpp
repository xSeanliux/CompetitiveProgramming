#include <iostream>
#include <math.h>
using namespace std;

double a, b, c, s, area, r;

int main(){
    while(cin >> a >> b >> c){
        if(!a || !b || !c){
            printf("The radius of the round table is: 0.000\n");
        } else {
            s = (a + b + c)/2;
             area = sqrt(s*(s-a)*(s-b)*(s-c));
             //r * s = area
             r = area/s;
             r *= 1000;
             r = round(r);
             r /= 1000;
             printf("The radius of the round table is: %.3f\n", r);

        }
    }
}
