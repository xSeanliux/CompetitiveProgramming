#include <iostream>
#include <math.h>
using namespace std;

double c, d, u, v;

int main(){
    cin >> c;
    for(int tt = 1; tt <= c; tt++){
        cin >> d >> u >> v;
        printf("Case %d: ", tt);
        if(u >= v || v == 0 || u == 0){
            printf("can't determine\n");
        } else {
            double fastest = d/v;
            double newV = sqrt(v*v - u*u);
            double shortest = d/newV;
            double time = shortest - fastest;
            time *= 1000;
            //cout << "time: " << time << endl;
            time = round(time);
            //cout << "time: " << time << endl;
            time /= 1000;
            printf("%.3f\n", time);
        }
    }
}
