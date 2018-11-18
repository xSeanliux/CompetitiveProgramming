#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

float h, u, f, d, day, c = 0; //height, v0, fatigue factor, distance falls
bool win = false;
int main(){
    while(cin >> h >> u >> d >> f){
        if(!h) return 0;
        float speedLoss =  u * f / 100.0; //loses this much speed every night
        float currentY = 0;
        day = 0;
        do{
            ++day;
            currentY += u;
            //cout << "Go up by " << u << endl;
            if(currentY > h) break;
            //cout << currentY << endl;
            u = ( u - speedLoss > 0 ) ? u - speedLoss : 0;
            currentY -= d;
        } while(currentY >= 0);
        //if(c) cout << endl;
        //else c++;
        if(currentY > h){
            cout << "success";
        } else {
            cout << "failure";
        }
        printf(" on day %.0f\n", day);
    }
}
