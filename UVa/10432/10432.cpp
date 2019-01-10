#include <iostream>
#include <math.h>

using namespace std;

double PI = acos(0);

double r, s;

int main(){
    while(cin >> r >> s){
        double angle = (180*(s-2))/(s);
        //cout << angle << " degrees" << endl;
        angle *= PI;
        angle /= 180;
        //cout << angle << " rads" << endl;
        double b = r * cos(angle);
        double h = r * sin(angle);
        double ans = h * b * s;
        //cout << ans << endl;
        ans *= 1000;
        round(ans);
        ans /= 1000;
        printf("%.3f\n", ans);
    }
}
