#include <iostream>
#include <math.h>
using namespace std;
int p,  q, r,  s,  t,  u;

double f(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s*tan(x) + t * x * x + u;
}

int main(){
    while(cin >> p >> q >> r >> s >> t >> u){
        if(!f(0)){
            cout << "0.0000" << endl;
            continue;
        } else if(!f(1)){
            cout << "1.0000" << endl;
            continue;
        }
        double U = 1, L = 0, M = 0.5; //make sure U is negative, L is positive
        while(abs(f(M)) > 0.000001 && U > L && M < 1 && M > 0){
            if(f(M) > 0){
                L = M;
            } else if(f(M) < 0){
                U = M;
            }
            M = (U + L)/2;
            //cout << "M = " << M << ", f(M) = " << f(M) << endl;
        }
        //cout << " M: " << M << endl;
        if(abs(f(M)) < 0.000001 && M <= 1 && M >= 0) printf("%.4f\n", M);
        else cout << "No solution" << endl;
    }

}

