#include <iostream>
#include <vector>
#include <cassert>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e3 + 326, INF = 1e15;

int N, F[maxN][maxN];
struct Edge {
    signed u, v;
    int w;
    Edge(){}
    Edge(signed u, signed v, int w): u(u), v(v), w(w){}
};

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

vector<Edge> edges;

bool isGreater(int a, int b, int c, int d) { // a / b > c / d
    return a * d > b * c;
}

signed main() {
    ericxiao
    cin >> N;
    int x;
    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) {
        cin >> x;
        if(x) edges.emplace_back(i, j, x);
    }
    for(int i = 1; i <= N; i++) edges.emplace_back(0, i, 0);
    N++;
    for(int i = 0; i <= N; i++) F[0][i] = INF;
    F[0][0] = 0;

    for(int k = 1; k <= N; k++) {
        for(int i = 0; i < N; i++) F[k][i] = INF;
        for(auto [u, v, w] : edges) F[k][v] = min(F[k][v], w + F[k - 1][u]);
    }
    int A = 1, B = 0;
    for(int v = 1; v < N; v++) {
        int a = -1, b = 1; 
        for(int k = 0; k < N; k++) {
            if(F[k][v] == INF || F[N][v] == INF) continue;
            if(isGreater(F[N][v] - F[k][v], N - k, a, b)) {
                a = F[N][v] - F[k][v];
                b = N - k;
            }
        }
        if(isGreater(A, B, a, b)) {
            A = a;
            B = b;
        }
    }
    int g = gcd(A, B);
    if(g){
        A /= g;
        B /= g;
    }
    if(A < 0) {
        A = -1, B = -1;
    }
    cout << A << " " << B << endl;
}
