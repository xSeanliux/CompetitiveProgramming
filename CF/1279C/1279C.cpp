#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

int T, n, m, x, hei[maxN], toTake[maxN], ans, mh;

signed main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> x;
            hei[x] = i;
        }
        for(int i = 0; i < m; i++){
            cin >> x;
            toTake[i] = hei[x];
        }
        ans = 0;
        for(int i = 0; i < m; i++){
            mh = toTake[i];
            ans += 2 * (mh - i) + 1;
            i++;
            while(i < m && toTake[i] < mh){
                ans++;
                i++;
            }
            i--;
        }
        cout << ans << '\n';
    }
}
