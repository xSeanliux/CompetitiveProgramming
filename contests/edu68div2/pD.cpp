#include <iostream>
using namespace std;

int Q, n, k;

int main(){
    cin >> Q;
    while(Q--){
        cin >> n >> k;
        if(k % 3){
            if(n % 3){
                cout << "Alice" << endl;
            } else {
                cout << "Bob" << endl;
            }
            continue;
        }
        n %= (2 * k + 2);
        if(n < k){
            if(n % 3){
                cout << "Alice" << endl;
            } else {
                cout << "Bob" << endl;
            }
        } else if(n == k){
            cout << "Alice" << endl;
        } else if(n < 2 * k){
            if(n % 3 != 1){
                cout << "Alice" << endl;
            } else {
                cout << "Bob" << endl;
            }
        } else {
            cout << "Alice" << endl;
        }
    }
}
