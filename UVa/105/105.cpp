#include <iostream>
using namespace std;


int hei[10069], L, H, R, mR = 0, cY = 0;
bool flag = false;
int main(){
    fill(hei, hei + 10069, 0);
    while(cin >> L >> H >> R){
        for(int i = L ; i < R; i++){
            hei[i] = max(hei[i], H);
        }
        //
        if(R > mR) mR = R;
    }
    //cout << "MR: " << mR << endl;
    //output time
    for(int i = 0 ; i <= mR + 1; i++){
        //cout << i << ": " << hei[i] << endl;

        if(hei[i] != cY){
            if(!flag)
                flag = true;
            else
                cout << " ";
            cout << i << " " << hei[i];
            cY = hei[i];
        }
        /*
        if(hei[i] > cY){
            cout << i << " " << hei[i] << " ";
            cY = hei[i];
        } else if(hei[i] < cY){
            cout << i-1 << " " << hei[i] << " ";
            cY = hei[i];
        }
        */
    }
    cout << endl;
}
