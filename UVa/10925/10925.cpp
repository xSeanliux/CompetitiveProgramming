#include <iostream>
#include <math.h>
using namespace std;

double p, b, n, s;

int main(){
    n = 1;
    while(cin >> b >> p){
        if(b == 0 && p == 0) return 0;
        s = 0;
        double _t = 0;
        for(int i = 0 ; i < b; i++){
            cin >> _t;
            s += _t;
        }
        printf("Bill #%.0f costs %.0f:", n, s);
        s /= p;
        s = floor(s);
        printf(" each friend should pay %.0f\n\n", s);
        n++;
    }

}
