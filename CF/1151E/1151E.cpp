#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

int N;
vector<int> a;

signed main(){
    ericxiao;
    cin >> N;
    int ans = 0;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N - 1; i++){
        if(a[i] == a[i + 1]) continue;
        if(a[i] < a[i + 1]){
            ans += (a[i]) * (a[i + 1] - a[i]);
        } else {
            ans += (a[i] - a[i + 1]) * (N - a[i] + 1);
        }
    }
    ans += a[N - 1] * (N - a[N - 1] + 1);
    cout << ans << endl;
}
