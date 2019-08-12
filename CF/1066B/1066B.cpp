#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long int
using namespace std;

string a, b;
int N, M;
const int MOD = 998244353;

signed main(){
    cin >> N >> M >> a >> b;
    int pre[N];
    int cP = 1, cS = a[0] - '0';
    pre[N - 1] = a[N-1] - '0';
    //printf("pre[%d] = %d\n", N - 1, pre[N-1]);
    for(int i = N - 2; i >= 0; i--){
        cP = 2 * cP % MOD;
        pre[i] = pre[i+1];
        pre[i] += (a[i] == '1') ? cP : 0;
        pre[i] %= MOD;
        //printf("pre[%d] = %d\n", i, pre[i]);
    }
    reverse(pre, pre + N);
    reverse(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < M; i++){
        if(b[i] == '1'){
            if(i < N){
                ans += pre[i];
            } else {
                ans += pre[N-1];
            }
            ans %= MOD;
        }
    }
    cout << ans << endl;
}
