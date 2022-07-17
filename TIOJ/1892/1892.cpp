#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MOD = 1e9 + 7, maxN = 111, maxL = 32;

int N, M[maxN][maxN], B[maxN][maxN], R[maxN][maxN], P[maxN], I[maxN][maxN], T[maxN][maxN], pows[maxL][maxN][maxN];

inline int add(int a, int b) {
    return (a + b >= MOD ? a + b - MOD : a + b);
}

void getPows() {
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) pows[0][i][j] = M[i][j];
    for(int t = 1; t < maxL; t++) {
       for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
            T[i][j] = 0;
            for(int k = 0; k < N; k++) T[i][j] = add(T[i][j], pows[t - 1][i][k] * pows[t - 1][k][j] % MOD);
        }
        for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) pows[t][i][j] = T[i][j]; 
    }
}

void pow(int e) {
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) B[i][j] = M[i][j];
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) R[i][j] = (i == j); 
    for(int t = 0; t < 31; t++) {
        if((e >> t) & 1) {
            for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
                T[i][j] = 0;
                for(int k = 0; k < N; k++) T[i][j] = add(T[i][j], R[i][k] * pows[t][k][j] % MOD);
            }
            for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) R[i][j] = T[i][j];
        }
    }
}

signed main() {
    ericxiao
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }
    int m, a, b, c;
    cin >> m;
    while(m--) {
        cin >> a >> b >> c;
        if(a == b) continue;
        M[b][a] = c;
    }
    for(int i = 0; i < N; i++) M[i][i] = 1;
    getPows();
    int Q, K;
    cin >> Q;
    while(Q--) {
        cin >> K;
        pow(K);
        for(int i = 0; i < N; i++) {
            int x = 0;
            for(int j = 0; j < N; j++) x = add(x, R[i][j] * P[j] % MOD);
            cout << x << " \n"[i == N - 1];
        }
    }
}

