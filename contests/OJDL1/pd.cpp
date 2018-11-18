#include <iostream>
using namespace std;

int n, k, a;

int main(){
    cin >> n >> k;
    if(n){
        cin >> a;
        cout << max(a, k) << endl;
    } else {
        cout << 0 << endl;
    }
}
