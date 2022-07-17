#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int T;

inline void solve(){
    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    int a = max(arr[0], arr[1]), b = max(arr[2], arr[3]);
    if(a > b) swap(a, b);
    sort(arr, arr + 4);
    if(a == arr[2] && b == arr[3]){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main(){
    cin >> T;
    while(T--){
        solve();
    }
}


