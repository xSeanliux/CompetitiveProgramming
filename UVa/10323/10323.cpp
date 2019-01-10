#include <iostream>
#include <math.h>
using namespace std;

int k;

int main(){
    while(cin >> k){
        if(k < 8){
            if(k < 0 && k % 2){
                cout << "Overflow!" << endl;
            } else {
                cout << "Underflow!" << endl;
            }
        } else if(k > 13){
            cout << "Overflow!" << endl;
        } else {
            long long int ans;
            switch(k){
            case 8:
                ans = 40320;
                break;
            case 9:
                ans = 362880;
                break;
            case 10:
                ans = 3628800;
                break;
            case 11:
                ans = 39916800;
                break;
            case 12:
                ans = 479001600;
                break;
            case 13:
                ans = 6227020800;
                break;
            }
            cout << ans << endl;
        }
    }

}
