#include "lib1945.h"
#include <iostream>

int len = 131072;
using namespace std;


int ans[131072];
bool currentBit, ask1, ask2, ask3;
int a[] = {1};
int main(){
    Init();
    a[0] = 0;
    currentBit = Query(1, a);
    ask1 = Query(1, a);
    if(ask1 != currentBit){
        currentBit = Query(1, a);
    }
    ans[0] = currentBit;
    for(int i = 1 ; i < len ; i++){
        a[0] = i;
        ask1 = Query(1, a);
        ask2 = Query(1, a);
        if(ask1 == ask2){
            if(currentBit != ask1){
                ans[len] = 1;
                currentBit = 1;
            } else {
                ans[len] = 0;
                currentBit = 0;
            }
        } else {
            ask3 = Query(1, a);
            if(currentBit != ask1){
                ans[len] = 1;
                currentBit = 1;
            } else {
                ans[len] = 0;
                currentBit = 0;
            }
        }
    }
    cout << ans[0];
    for(int i = 1; i < len; i++){
        cout << " " << ans[i];
    }

}
