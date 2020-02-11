#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second

#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

int t, n, k, arr[maxN];

inline int abs(int a){
    return (a < 0 ? -a : a);
}

int main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> n;
        bool can = false;
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        for(int i = 2; i <= n && !can; i++){
            if(abs(arr[i] - arr[i - 1]) > 1){
                cout << "YES" << endl;
                cout << i - 1 << " " << i << endl;
                can = true;
                break;
            }
        }
        if(!can) cout << "NO" << endl;
    }
}
