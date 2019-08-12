#include <iostream>
#include <numeric>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5;
int N, k, suf[maxN + 10];

signed main(){
    ericxiao;
    cin >> N >> k;
    suf[N] = 0;
    for(int i = 0; i < N; i++){
        cin >> suf[i];
    }
    for(int i = N - 1; i >= 0; i--){
        suf[i] += suf[i + 1];
    }
    sort(suf + 1, suf + N, greater<int>() );
    int ans = accumulate(suf, suf + k, 0LL); //will overflow! Must add 0LL
    cout << ans << endl;
}
