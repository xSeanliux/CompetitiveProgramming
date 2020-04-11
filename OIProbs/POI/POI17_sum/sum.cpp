#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
//#define ll __int128
using namespace std;

const int maxN = 31;

unsigned long long int C[maxN][maxN], k, ways[31][201];
int ans[maxN + 10], s, m, q, _k;

inline int digsum(int x){
    int r = 0;
    while(x){
        r += x % 10;
        x /= 10;
    }
    return r;
}

void solve(){
    for(int d = maxN; d >= 1; d--){
        for(int x = 0; x < 10; x++){
            unsigned long long int S = 0;
            for(int i = 0; i <= x && s - i >= 0; i++){
                S += ways[d - 1][s - i];
            }
            cout << "d = " << d << ", x = " << x << ", S = " << S << ", k = " << k << endl;
            if(S >= k){
                ans[d] = x;
                unsigned long long int S = 0;
                for(int i = 0; i < x; i++){
                    S += ways[d - 1][s - i];
                }
                k -= S;
                s -= (x);
                break;
            }
        }
    }
    for(int i = maxN; i; i--) cout << ans[i];
    cout << endl;
}

int main(){
    ericxiao;
    ways[0][0] = 1;
    for(int d = 1; d <= 30; d++){
        for(int s = 0; s <= 200; s++){
            for(int x = 0; x < 10 && x <= s; x++){
                ways[d][s] += ways[d - 1][s - x];
            }
            cout << "Ways[" << d << "][" << s << "] = " << ways[d][s] << endl;
        }
    }
    cin >> s >> m >> q;
    while(q--){
        cin >> k;
        //k = _k;
        solve();
    }
}
