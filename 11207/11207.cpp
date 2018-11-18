#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int nPaper, W, H, mI, mDi;

int main(){
    while(cin >> nPaper){
        if(!nPaper) return 0;
        mDi = 1;
        for(int i = 1; i <= nPaper; i++){
            cin >> W >> H;
            if(W < H) swap(W, H); //H < W
            int d;
            if(H*4 <= W){
                cout << "d = H" << endl;
                d = H;
            } else {
                d = W/4;
                cout << "d = W/4" << endl;
            }
            cout << "d: " << d << endl;
            if(d > mDi){
                mI = i;
                mDi = d;
            }
        }
        cout << mI << endl;
    }
}
