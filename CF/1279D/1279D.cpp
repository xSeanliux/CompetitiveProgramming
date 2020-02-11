#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e6 + 10, MOD = 998244353;

int N, k, a, ans = 0;

int has[maxN];
vector<int> person[maxN];

int modexp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = modexp(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

inline int add(int x, int y){
    return (x + y >= MOD ? x + y - MOD : x + y);
}

inline int inv(int x){
    return modexp(x, MOD - 2);
}


signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> k;
        person[i].resize(k);
        for(int j = 0; j < k; j++){
            cin >> person[i][j];
            has[person[i][j]]++;
        }
    }
    for(int i = 0; i < N; i++){
        for(int a : person[i]){
            ans = add(ans, inv(N) * inv(person[i].size()) % MOD * has[a] % MOD * inv(N) % MOD);
            //1/N/person[i].size() * has[a]
        }
    }
    cout << ans << endl;
}
