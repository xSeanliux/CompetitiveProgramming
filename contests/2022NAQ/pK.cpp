#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 326;
int arr[maxN], N, M, sum;

inline void solve() {
    int T;
    cin >> T;
    T = sum - T;
    //cout << "tgt = " << T << endl;
    int curSum = 0;
    for(int l = 0, r = 0; l < N; l++) {
        while(r < N && (curSum + arr[r]) <= T) curSum += arr[r++];
        if(curSum == T) {
            cout << "Yes" << endl;
            return;
        }
        //cout << "l = " << l << ", r = " << r << ", cursum = " << curSum << endl;
        if(l < r) curSum -= arr[l];
        r = max(l + 1, r);
    }
    cout << "No" << endl;
}

int main() {
    ericxiao
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    while(M--) {
        solve();
    }
}
