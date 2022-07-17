#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e3 + 326;
int arr[maxN];

inline void solve(int t) {
    cout << "Case #" << t << ": ";
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> arr[i];
    if(K == 1) {
        int sx = 0, sx2 = 0;
        for(int i = 0; i < N; i++) {
            sx += arr[i];
            sx2 += arr[i] * arr[i];
        }
        if(sx == 0) {
            if(sx2 == 0) {
                cout << "1\n";
                return;
            }
            cout << "IMPOSSIBLE\n";
            return;
        }

        int y = (sx2 - sx * sx) / (2 * sx);
            if((y * 2 * sx) == (sx2 - sx * sx)) {
            cout << y << endl;
        } else {
            cout << "IMPOSSIBLE\n";
        }
        return;
    }
    int A = 0, B = 0;
    for(int i = 0; i < N; i++) {
        A += B * arr[i];
        B += arr[i];
    }
    int a = 1 - B;
    int b = B * B - A - B;
    cout << a << " " << b << "\n";
}

signed main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) solve(i);
}
