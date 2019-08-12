#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

const int MOD = 998244353;
int N;
vector<int> A, B, inds;


signed main(){
    cin >> N;
    A.resize(N); B.resize(N); inds.resize(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        A[i] *= (i + 1);
        A[i] *= (N - i);
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
        inds[i] = i;
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < N; i++){
        A[i] %= MOD;
    }
    sort(B.begin(), B.end());
    int ans = 0;
    for(int i = 0; i < N; i++){
        ans += ((A[i] * B[N - i - 1] % MOD));
        ans %= MOD;
    }
    cout << ans << endl;
}
