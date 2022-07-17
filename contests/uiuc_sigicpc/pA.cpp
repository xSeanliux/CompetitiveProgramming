#include <iostream>
using namespace std;

const int maxN = 5e5 + 326;
int T, arr[maxN];

void run(int l, int r) {
    if(r - l <= 1) return;
    int minIndex = l; 
    for(int i = l; i < r; i++) if(arr[i] < arr[minIndex]) minIndex = i;
    for(int i = minIndex - 1; i >= l; i--) swap(arr[i], arr[i + 1]);
    if(minIndex == l) minIndex++;
    run(minIndex, r);
}

inline void solve() {
    int N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    run(0, N);
    for(int i = 0; i < N; i++) cout << arr[i] << " \n"[i == N - 1];
}

int main() {
    cin >> T;
    while(T--) {
        solve();
    }
}
