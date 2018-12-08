#include <iostream>
#include <math.h>
#define PI 2*acos(0)
using namespace std;

int N, D, L;

int main(){
    cin >> N;
    while(N--){
        cin >> D >> L;
        double ans = PI * L * sqrt(L * L - D * D) / 4;
        printf("%.3f\n", ans);
    }
}
