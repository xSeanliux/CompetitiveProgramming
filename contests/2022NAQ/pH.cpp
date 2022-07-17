#include <iostream>
using namespace std;

int main(){
    int N, x, fn;
    bool f = false;
    cin >> N;
    while(N--){
        cin >> x;
        if(!f) {
            fn = x;
            f ^= 1;
        } else {
            if(!(x % fn)) {
                cout << x << endl;
                f ^= 1;
            }
        }
    }
}
