#include <iostream>
#include <math.h>
using namespace std;

int c;
double x, y, r;

int main(){
    cin >> c;
    for(int i = 0 ; i < c ; i++){
        cin >> x >> y >> r;
        double dist = sqrt( (x*x) + (y*y));
        double rDist = round(dist * 100) / 100;
        printf("%.2f %.2f\n", r - dist, r + dist );
    }

}
