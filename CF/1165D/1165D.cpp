#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int q, n, ans, dc;
vector<int> divs;

signed main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> n;
        divs.resize(n);
        for(int i = 0; i < n; i++) cin >> divs[i];
        sort(divs.begin(), divs.end());
        ans = divs[0] * divs[n - 1];
        bool canDo = true;
        for(int d : divs) if(ans % d){
            cout << -1 << endl;
            canDo = false;
            break;
        }
        dc = 0;
        for(int i = 2; i * i <= ans && canDo; i++){
            if(!(ans % i)){
                dc += 1 + (i * i != ans);
            }
            if(dc > n){
                cout << -1 << endl;
                canDo = false;
                break;
            }
        }
        if(canDo){
            cout << ans << endl;
        }
    }
}
