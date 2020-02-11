#include <iostream>
#include <vector>
#include <map>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 3e5 + 10;

int n, frq[maxN], k;

signed main(){
    ericxiao;
    cin >> n;
    int ans = 0, cnt = 0, match;
    for(int i = 0; i < n; i++){ //try to match with previous ones first then match with self
        cin >> frq[i];
        match = min(frq[i] / 2, cnt);
        ans += match;
        frq[i] -= match * 2;
        cnt -= match;

        ans += frq[i] / 3;
        frq[i] %= 3;
        if(frq[i] == 2){
            if(cnt){
                ans++;
                cnt--;
            } else {
                cnt += 2;
            }
        } else {
            cnt += frq[i];
        }
    }
    cout << ans << endl;
}
