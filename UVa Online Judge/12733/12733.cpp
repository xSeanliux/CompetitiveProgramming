#include <iostream>
#include <math.h>
using namespace std;

int C, coins, bool b;

int test(int l, int r){
    cout << "Test";
    for(int i = l ; i <= r; i++){
        cout << " " << i;
    }
    cout << endl;
    cout << flush;
    int res;
    cin >> res;
    return res;
}



int main(){
    cin >> C;
    while(C--){
        cin >> coins;
        int l = 1, r = ceil(coins/3)*2;
        while(l - r > 1){
            int range = r - l;
            int res = test(l, r);
            if(res == 1){ //left > right
                right = l + floor(range/3);
            } else if(res == -1){ //left < right
                left = l + 2*()
            } else { // equal
                left = ceil(coins/3)*2 + 1;
                right =
            }
        }
    }
}
