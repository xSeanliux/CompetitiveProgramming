#include <iostream>
#define ll long long int
using namespace std;

const int maxN = 3326;
int N;
ll K, arr[maxN], emp[maxN];

inline ll Abs(ll x) { return x < (ll)0 ? -x : x; }

int main() {
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        if(!arr[i]) emp[i]++;
        emp[i] += emp[i - 1];
        arr[i] += arr[i - 1];
    }
    if(K * emp[N] < Abs(arr[N])) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = 1;
    for(int l = 1; l <= N; l++) for(int r = l + 1; r <= N; r++) {
        ll S = arr[r] - arr[l];
        ll slots = emp[r] - emp[l];
        ll R = slots * K, L = -slots * K;
        R = min(R, (emp[N] - slots) * K - arr[N]);
        L = max(L, -(emp[N] - slots) * K - arr[N]);
        /*
        cout << "l = " << l << ", r = " << r << endl;
        cout << "S = " << S << endl;
        cout << "slots = " << slots << endl;
        cout << "L = " << L << endl;
        cout << "R = " << R << endl;
        */
        if(L > R) continue;
        ans = max(ans, max(Abs(S + R), Abs(S + L)) + (ll)1);
        //cout << "ans = " << ans << endl;
    }
    cout << ans << endl;
}
