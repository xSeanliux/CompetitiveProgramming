#include <iostream>
#include <math.h>
#define PI acos(-1)
using namespace std;

double L, W, H, theta;

int main(){
    while(cin >> L >> W >> H >> theta){
        double boundary = atan(H/L), ans;
        if(theta*PI/180 < boundary) ans = (L*H - (tan(theta*PI/180) * L * L / 2));
        else ans = (tan(PI/2 - theta*PI/180) * H * H / 2);
        printf("%.3f mL\n", ans*W);
    }
}
