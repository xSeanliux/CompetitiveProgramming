#include <iostream>
using namespace std;

struct Rect{
    int dims[2];
    char c;
    Rect(){}
    Rect(int x, int y){
        dims[0] = x;
        dims[1] = y;
    }
    int area(){
        return dims[0] * dims[1];
    }
} rects[3];

int Sqrt(int x){
    for(int i = 1; i * i <= x; i++){
        if(i * i == x) return i;
    }
    return -1;
}

int main(){
    int x, y, mV = 0, len, soa = 0;
    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        if(x > y) swap(x, y);
        rects[i] = Rect(x, y);
        rects[i].c = 'A' + i;
        mV = max(mV, y);
        soa += rects[i].area();
    }
    len = Sqrt(soa);
    if(len == -1 || len != mV){
        cout << -1 << endl;
        return 0;
    }
    //case 1: stripes
    bool isStripe = true;
    for(int i = 0; i < 3; i++) if(rects[i].dims[1] != len) isStripe = false;
    if(isStripe){
        cout << len << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < rects[i].dims[0]; j++){
                for(int k = 0; k < len; k++){
                    cout << rects[i].c;
                }
                cout << endl;
            }
        }
        return 0;
    }
    //case 2: mouse
    int lc = 0, ind = 0;
    for(int i = 0; i < 3; i++){
        if(rects[i].dims[1] == len){
            lc++;
            ind = i;
        }
    }
    if(lc != 1){
        cout << -1 << endl;
        return 0;
    }
    swap(rects[0], rects[ind]);
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            if(rects[1].dims[i] + rects[2].dims[j] == len && rects[1].dims[i^1] == rects[2].dims[j^1] && rects[2].dims[j^1] + rects[0].dims[0] == len){ //found our man
                cout << len << endl;
                for(int k = 0; k < rects[0].dims[0]; k++){
                    for(int l = 0; l < len; l++){
                        cout << rects[0].c;
                    }
                    cout << endl;
                }
                for(int k = 0; k < rects[1].dims[i ^ 1]; k++){
                    for(int l = 0; l < rects[1].dims[i]; l++){
                        cout << rects[1].c;
                    }
                    for(int l = 0; l < rects[2].dims[j]; l++){
                        cout << rects[2].c;
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }
}
