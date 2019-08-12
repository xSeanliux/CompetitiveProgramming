#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double l, n, C, nl;

int main(){
    while(cin >> l >> n >> C){
        if(l < -1e-9 && n < -1e-9 && C < -1e-9) return 0;
        nl = (1 + n * C) * l;
        double U = acos(-1)/2, L = 0, M = (U + L) / 2;
        while(fabs(1e3*sin(M)/M - 1e3*l/nl) > 1e-15){
            if(1e3*sin(M)/M > 1e3*l/nl){
                L = M;
            } else {
                U = M;
            }
            M = (U + L) / 2;
        }
        //printf("theta = %lf\n", M);
        //if(M > 3) printf("0.000\n");
        printf("%.3lf\n", l * tan(M/2) / 2);
    }
}
