#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;

int arr[maxN];

inline void solve(int t) {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);
    int cur = 1;
    for(int i = 0; i < N; i++) {
        if(arr[i] >= cur) cur++;
    }
    cout << "Case #" << t << ": " << cur - 1 << endl;
}
int main() {
    ericxiao
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) solve(i);
}
