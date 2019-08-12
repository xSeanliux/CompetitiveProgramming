#include <iostream>
#include <math.h>
using namespace std;

const long double PI = acos(-1);

int N;
double R, r, B, O;

int main(){
    while(cin >> R >> N){
        if(N == 1){
            r = R;
            B = O = 0;
        } else if(N == 2){
            r = R/2;
            B = 0;
            O = PI*(R*R - 2*r*r);
        } else {
            r = R*sin(PI/N)/(1 + sin(PI/N));
            B = (R - r) * r * cos(PI/N) * N - PI*r*r*(N-2)/2;
            O = PI*R*R - N * PI * r * r - B;
        }
        printf("%.10f %.10f %.10f\n", r, B, O);
    }
}
