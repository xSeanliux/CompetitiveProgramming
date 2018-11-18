#include <iostream>
#include <math.h>
using namespace std;

double L, W, H, theta;

int main(){
    while(cin >> L >> W >> H >> theta){
        cout << (L*H - (tan(theta) * L * L / 2))*W << endl;
    }

}
