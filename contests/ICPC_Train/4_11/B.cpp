#pragma GCC optimize("Ofast", "no-stack-protector", "no-math-errno", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,avx")
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int maxN = 1e5 + 1, MOD = 1e9 + 9;

bitset<maxN>* basis[maxN];

int N, M, rk = 0;

ll modexp(ll b, ll e) {
  ll r = 1;
  for(int i = 0; i < 64; i++) {
    if((e >> i) & 1) r = r * b % MOD;
    b = b * b % MOD;
  }
  return r;
}

void elim(bitset<maxN> *v) {
  for(int i = v->_Find_first(); i < N; i = v->_Find_first()) {
    if(v->count() == 0) return;
    if(basis[i] && (*basis[i])[i]) (*v) ^= (*basis[i]);
    else {
      basis[i] = v;
      rk++;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> N >> M;
  bitset<maxN>* vec;
  vec->reset();
  for(int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    (*vec)[u] = 1, (*vec)[v] = 1;
    elim(vec);
    vec->reset();
  }
  cout << modexp(2LL, (ll)(M - rk)) << endl;
}