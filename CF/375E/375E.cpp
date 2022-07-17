#include <bits/stdc++.h>
using namespace std;

const int MAXN = 511;
const int MAXM = 511;
const double eps = 1E-10;
double a[MAXN][MAXM], b[MAXN], c[MAXM], d[MAXN][MAXM];
double x[MAXM];
int ix[MAXN + MAXM]; // !!! array all indexed from 0
// max{cx} subject to {Ax<=b,x>=0}
// n: constraints, m: vars !!!
// x[] is the optimal solution vector
// usage : 
// value = simplex(a, b, c, N, M);
double simplex(double a[MAXN][MAXM], double b[MAXN],
               double c[MAXM], int n, int m){
  ++m;
  int r = n, s = m - 1;
  memset(d, 0, sizeof(d));
  for (int i = 0; i < n + m; ++i) ix[i] = i;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) d[i][j] = -a[i][j];
    d[i][m - 1] = 1;
    d[i][m] = b[i];
    if (d[r][m] > d[i][m]) r = i;
  }
  for (int j = 0; j < m - 1; ++j) d[n][j] = c[j];
  d[n + 1][m - 1] = -1;
  for (double dd;; ) {
    if (r < n) {
      int t = ix[s]; ix[s] = ix[r + m]; ix[r + m] = t;
      d[r][s] = 1.0 / d[r][s];
      for (int j = 0; j <= m; ++j)
        if (j != s) d[r][j] *= -d[r][s];
      for (int i = 0; i <= n + 1; ++i) if (i != r) {
        for (int j = 0; j <= m; ++j) if (j != s)
          d[i][j] += d[r][j] * d[i][s];
        d[i][s] *= d[r][s];
      }
    }
    r = -1; s = -1;
    for (int j = 0; j < m; ++j)
      if (s < 0 || ix[s] > ix[j]) {
        if (d[n + 1][j] > eps ||
            (d[n + 1][j] > -eps && d[n][j] > eps))
          s = j;
      }
    if (s < 0) break;
    for (int i = 0; i < n; ++i) if (d[i][s] < -eps) {
      if (r < 0 ||
          (dd = d[r][m] / d[r][s] - d[i][m] / d[i][s]) < -eps ||
          (dd < eps && ix[r + m] > ix[i + m]))
        r = i;
    }
    if (r < 0) {
        x[0] = -1;
        return -1; // not bounded
    }
  }
  if (d[n + 1][m] < -eps) {
      x[0] = -1;
      return -1; // not executable
  }
  double ans = 0;
  for(int i=0; i<m; i++) x[i] = 0;
  for (int i = m; i < n + m; ++i) { // the missing enumerated x[i] = 0
    if (ix[i] < m - 1){
      ans += d[i - m][m] * c[ix[i]];
      x[ix[i]] = d[i-m][m];
    }
  }
  return ans; 
}


const int maxN = 526;
int N;
double X, dist[maxN][maxN];

int main() {
   cin >> N >> X; 
   for(int i = 0; i < N; i++) b[i] = -1;
   b[N] = 0;
   for(int i = 0; i < N; i++) {
        int co;
        cin >> co;
        if(!co) c[i] = -1;
        else {
            c[i] = 0;
            b[N]++;
        }
   }
   b[N + 1] = -b[N] + eps;
   b[N] += eps;
   for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) dist[i][j] = (i == j ? 0 : 1e15);
   for(int i = 0; i < N - 1; i++) {
        int u, v;
        double w;
        cin >> u >> v >> w;
        dist[u - 1][v - 1] = dist[v - 1][u - 1] = w;
   }
   for(int k = 0; k < N; k++) for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
   }
   for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
        if(dist[i][j] < X + eps) a[i][j] = -1;
        else a[i][j] = 0;
   }
   for(int i = 0; i < N; i++) {
       a[N][i] = 1;
       a[N + 1][i] = -1;
   }
   double ans = simplex(a, b, c, N + 2, N);
   if(x[0] < 0) {
       cout << -1 << endl;
   } else cout << (long long int)(round(-ans)) << endl;
}

