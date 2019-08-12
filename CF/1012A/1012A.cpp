#include <iostream>
#include <algorithm>
#define int unsigned long long int
using namespace std;

int N, vals[(int)2e5 + 10];

signed main(){
    cin >> N;
    for(int i = 0; i < 2 * N; i++) cin >> vals[i];
    int ans = 1e18 + 20;
    sort(vals, vals + 2 * N);
    ans = (vals[N - 1] - vals[0]) * (vals[2 * N - 1] - vals[N]);
    for(int i = 1; i <= N - 1; i++){ //i < N - 1 will WA ;-;
        ans = min(ans, (vals[2 * N - 1] - vals[0]) * (vals[i + N - 1] - vals[i]) );
    }
    cout << ans << endl;

}
