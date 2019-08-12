#include <iostream>
#include <math.h>
#define PI acos(-1)
using namespace std;

double n, r;

int main(){
    for(int n = 3; n <= 100; n++){
        for(int r = 1; r <= 100; r++){
            double LR = 0, UR = 1000000, MR = (LR + UR)/2, targetSin = sin(PI/n);
        while(abs(MR/(r + MR) - targetSin) > 0.0000000001){
            if(MR/(r + MR) > targetSin) UR = MR;
            else LR = MR;
            MR = (LR + UR)/2;
        }
        printf("%d %d %.3f\n", n, r, MR);
        }
    }

}
