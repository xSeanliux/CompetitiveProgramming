#include <iostream>
#include <math.h>
using namespace std;


double abss(double a){
    if(a < 0){
        return -a;
    } else{
        return a;
    }
}

double N, P, K;
//given n, p, find k such that k^n = p
int main(){
    while(cin >> N >> P){
        if(P == 0){
            cout << "0" << endl;
        } else {
        double lowerBound = 1;
        double upperBound = 100000000000;
        double middle = (lowerBound + upperBound)/2;
        double K = pow(middle, N);
        double E = abss(K-P);
        while(E >= 0.000001){
            //cout << "Error: " << E << endl;
            if(K > P){
                upperBound = middle;
            } else {
                lowerBound = middle;
            }
            middle = (lowerBound + upperBound)/2;
            K = pow(middle, N);
            E = abss(K-P)/P * 100000;
            //cout << middle << endl;
        }
        double ans = round(middle);
        printf("%.0F\n", ans);
        }

    }

}
