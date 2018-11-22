#include <iostream>
#include <math.h>
using namespace std;

int C;
double d;

int main(){
    cin >> C;
    while(C--){
        cin >> d;
        if(d < 4 && d > 0){
            cout << "N" << endl;
        } else {
            double a = ( d + sqrt(d*(d - 4)) ) / 2;
            double b = ( d - sqrt(d*(d - 4)) ) / 2;
            printf("Y %.9f %.9f\n", a, b);
        }
    }
}
