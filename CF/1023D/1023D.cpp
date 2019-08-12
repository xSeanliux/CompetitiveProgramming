#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double x1, Y1, x2, y2;
int a, b, c;

double getDist(double a, double b, double c, double d){
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main(){
    cin >> a >> b >> c >> x1 >> Y1 >> x2 >> y2;
    cout << fixed << setprecision(10);
    double ans = fabs(x1 - x2) + fabs(y2 - Y1);
    if(!a || !b){
        cout << ans << endl;
        return 0;
    }
    double dist;
    //VV
    dist = fabs(Y1 - (-(a * x1 + c)/b)) + getDist(x1, (-(a * x1 + c)/b), x2, (-(a * x2 + c)/b)) + fabs(y2 - (-(a * x2 + c)/b));
    ans = min(ans, dist);
    //VH
    dist = fabs(Y1 - (-(a * x1 + c)/b)) + getDist(x1, (-(a * x1 + c)/b), -(c + b * y2)/a, y2) + fabs(x2 - (-(c + b * y2)/a));
    ans = min(ans, dist);
    //HV
    dist = fabs(x1 - (-(c + b * Y1)/a)) + getDist((-(c + b * Y1)/a), Y1, x2, -(a * x2 + c)/b) + fabs(y2 - (-(a * x2 + c)/b));
    ans = min(ans, dist);
    //HH
    dist = fabs(x1 - (-(c + b * Y1)/a)) + getDist((-(c + b * Y1)/a), Y1, -(c + b * y2)/a, y2) + fabs(x2 - (-(c + b * y2)/a));
    ans = min(ans ,dist);
    cout << ans << endl;
}

