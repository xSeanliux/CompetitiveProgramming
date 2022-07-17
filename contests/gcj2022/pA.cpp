#include <iostream>
using namespace std;

inline void solve(int T) {
    int N, M;
    cout << "Case #" << T << ":" << endl;
    cin >> N >> M;
    cout << "..+";
    for(int i = 1; i < M; i++) {
        cout << "-+";
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        if(i == 0) cout << ".";
        else cout << "|";
        for(int j = 0; j < M; j++) {
            cout << ".|";
        }
        cout << endl;
        cout << "+";
        for(int j = 0; j < M; j++) cout << "-+";
        cout << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) solve(t);
}
