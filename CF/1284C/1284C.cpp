#include <iostream>
#define int long long int
using namespace std;

const int maxN = 3e5 + 10;

int N, M, ans, fact[maxN];

signed main(){
    cin >> N >> M;

    fact[0] = 1;
    for(int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % M;

    for(int l = 1; l <= N; l++){
        ans = (ans + (N - l + 1) * (N - l + 1) % M * fact[l] % M * fact[N - l] % M) % M;
    }

    cout << ans << endl;
}
