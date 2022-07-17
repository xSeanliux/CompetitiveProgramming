#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
#define all(x) x.begin(),x.end()
using namespace std;

inline void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    string a, b;
    cin >> a >> b;
    sort(all(a));
    sort(all(b));
    queue<char> A, B, C;
    for(char c : a) A.push(c);
    for(char c : b) B.push(c);
    int cur = 0;
    while(A.size() && B.size()) {
        if(cur == K) {
            C.push(B.front());
            B.pop();
            cur = -1;
        } else if(cur == -K) {
            C.push(A.front());
            A.pop();
            cur = 1;
        } else if(A.front() < B.front()) {
            C.push(A.front());
            A.pop();
            cur = max(cur + 1, 1);
        } else {
            C.push(B.front());
            B.pop();
            cur = min(cur - 1, -1);
        }
    }
    while(C.size()) {
        cout << C.front();
        C.pop();
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
}
