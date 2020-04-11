#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
//#define ll __int128
using namespace std;

const int maxN = 51;

long long int C[maxN][maxN], k;
int ans[maxN], s, m, q, _k;

inline int digsum(int x){
    int r = 0;
    while(x){
        r += x % 10;
        x /= 10;
    }
    return r;
}

inline long long int choose(int n, int k){
    if(k > n){
        return 1;
    }
    return C[n][k];
}

void solve(){
    for(int i = 0; i < maxN; i++){
        if(!k){
            continue;
            ans[i] = 0;
        }
        for(int x = 0; x < 10; x++){
            long long int s = 0;
            for(int j = 0; j < x && j <= k; j++){
                cout << "Adding " << k - j + (maxN - i - 1) - 1 << " choose " << (maxN - i - 1) - 1 << endl;
                s += choose(k - j + (maxN - i - 1) - 1, k - j);
            }
            if(s > k){
                ans[i] = x - 1;
                s = 0;
                for(int j = 0; j < x - 1; j++){
                    s += choose(k - j + (maxN - i - 1) - 1, k - j);
                }
                k -= s;
                break;
            }
        }
    }
    for(int i = 0; i < maxN; i++){
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    ericxiao;
    C[0][0] = 1;
    for(int i = 1; i < maxN; i++){
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++){
            C[i][j] = C[i][i - j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    cin >> s >> m >> q;
    while(q--){
        cin >> k;
        //k = _k;
        solve();
    }
}

