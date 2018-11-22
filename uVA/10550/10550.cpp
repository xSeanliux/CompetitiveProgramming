#include <iostream>
using namespace std;
int currentPos, a1, a2, a3;

int totalDegs;

int turn(int from, int to, bool dir){
    int k;
    if(dir){
        k = (from - to)*9;
    } else {
        k = (to - from)*9;
    }
    if(k < 0){
        k += 360;
    }
    return k;
}

int main(){
    while(cin >> currentPos >> a1 >> a2 >> a3){
        if(currentPos == 0 && a1 == 0 && a2 == 0 && a3 == 0){
            return 0;
        }
        totalDegs = 720;
        totalDegs += turn(currentPos, a1, 1);
        currentPos = a1;
        totalDegs += 360;
        totalDegs += turn(currentPos, a2, 0);
        currentPos = a2;
        totalDegs += turn(currentPos, a3, 1);
        cout << totalDegs << endl;
    }
}
