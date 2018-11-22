#include <iostream>
#include <math.h>
#include <string.h>
#define PI acos(-1)
using namespace std;

string s;
int C, N, angle;
double x, y;


double cosDeg(int ang){
    double ang = PI/180 * ang;
    return cos(ang);
}

double sinDeg(int ang){
    double ang = PI/180 * ang;
    return sin(ang);
}

int main(){
    cin >> C;
    while(C--){
        cin >> N;
        angle = x = y = 0;
        for(int i = 0 ; i < N; i++){
            cin >> s >> arg;
            if(s == 'fd'){
                x += arg * cosDeg(angle);
                y += arg * sinDeg(angle);
            } else if(s == 'bk'){
                x -= arg * cosDeg(angle);
                y -= arg * sinDeg(angle);
            } else if(s == 'lt'){
                angle += arg;
            } else {
                angle -= arg;
            }
        }
        printf("%d")
    }
}
