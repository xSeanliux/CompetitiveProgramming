#include <iostream>
#include <cassert>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, INV2 = 5e8 + 4, maxN = 100;
int P[maxN], A[maxN], mpow[1500][200], inv[1500];

inline int add(int a, int b) {
  return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int modexp(int b, int e) {
  //cout << "b = " << b << ", e = " << e << endl;
  assert(b < 1500);
  assert(e < 200);
  return mpow[b][e];
}

inline int modinv(int x) {
  assert(x < 1500);
  return inv[x];
}

inline int sub(int a, int b) {
  return (a >= b) ? a - b : a - b + MOD;
}

inline int geo(int n, int k) { //1 + n + n^2 + ... + n^k
  if(n == 0) return 0;
  if(n == 1) return k;
  return sub(modexp(n, k + 1), 1) * modinv(sub(n, 1)) % MOD;
}

inline void solve(int t) {
  int C, ans = 0; 
  cin >> C;
  int N = 1;
  for(int i = 0; i < C; i++) {
    cin >> P[i] >> A[i];
    N = N * modexp(P[i], A[i]) % MOD;
  }
  for(int m = 0; m < (1 << C); m++) {
    int sumQ = 1, sumP = 1, szP = 1, szQ = 1;
    for(int i = 0; i < C; i++) {
      if((m >> i) & 1) { //p has to be full
        sumP = sumP * modexp(P[i], A[i]) % MOD;
        sumQ = sumQ * geo(P[i], A[i]) % MOD;
        szQ = szQ * (1 + A[i]) % MOD;
      } else { //p does not have this full
        sumP = sumP * geo(P[i], A[i] - 1) % MOD;
        sumQ = sumQ * modexp(P[i], A[i]) % MOD;
        szP = szP * (A[i]) % MOD;
      }
    }
    ans = add(ans, add((sumQ * szP) % MOD, (sumP * szQ) % MOD)); 
  }
  cout << "Case " << t << ": " << add(ans, 2 * N % MOD) * INV2 % MOD << endl;
}

signed main() {
  for(int i = 1; i < 1500; i++) {
    mpow[i][0] = 1;
    for(int j = 1; j < 200; j++) {
      mpow[i][j] = mpow[i][j - 1] * i % MOD;
    }
  }
  inv[1] = 1;
  for(int i = 2; i < 1500; i++) {
    inv[i] = sub(MOD, MOD / i) * inv[MOD % i] % MOD;
    assert(inv[i] * i % MOD == 1);
  }
  int T;
  cin >> T;
  for(int t = 1; t <= T; t++) solve(t);
}