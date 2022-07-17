#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
#include <utility>
#include <math.h>
#include <numeric>
using namespace std;

inline int modexp(int b, int e, int p) {
  int r = 1;
  for(int i = 0; i < 32; i++) {
    if((e >> i) & 1) r = r * b % p;
    b = b * b % p;
  }
  return r;
}

inline int modinv(int x, int p) {
  return modexp(x, p - 2, p);
}

vector<int> gauss_elim(vector<vector<int>> eq, vector<int> b, int p){
  int N = eq.size();
  vector<int> ans = vector<int>(N);
  for(int i = 0; i < N; i++) {
    assert(0 <= b[i] && b[i] < p);
    for(int j = 0; j < N; j++) {
      assert(0 <= eq[i][j] && eq[i][j] < p);
    }
  }
  for(int i = 0; i < N; i++) {
    if(eq[i][i] == 0) {
      for(int j = i + 1; j < N; j++) {
        if(eq[j][i] != 0) {
          swap(b[i], b[j]);
          for(int k = 0; k < N; k++) {
            swap(eq[i][k], eq[j][k]);
          }
          break;
        } 
      }
    }
    if(eq[i][i] == 0) continue;
    for(int j = i + 1; j < N; j++) {
      if(!eq[j][i]) continue;
      int factor = eq[j][i] * modinv(eq[i][i], p) % p;
      for(int k = i; k < N; k++) {
        eq[j][k] = (p + eq[j][k] - eq[i][k] * factor % p) % p;
      }
      b[j] = (b[j] - b[i] * factor % p + p) % p;
    }
  }
  for(int i = N - 1; i >= 0; i--) {
    if(eq[i][i] == 0) {
      if(b[i] == 0) {
        ans[i] = 0;
        continue;
      } else {
        ans[0] = -1;
        return ans;
      }
    }
    ans[i] = b[i] * modinv(eq[i][i], p) % p;
    for(int j = i - 1; j >= 0; j--) {
      b[j] = (b[j] - eq[j][i] * ans[i] % p + p) % p;
    }
    //if(ans[i] < 0) ans[i] += p;
  }
  return ans;
}
void solve(){
    int n,m,p;
    cin>>n>>m >> p;
    vector<vector<int>> eq(n * m, vector<int>(n * m, 0));
    vector<int> b(n * m, 0);
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
          cin >> b[i * m + j];
          b[i * m + j] = p - b[i * m + j];
      }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){
                    eq[i*m + j][k*m + l] = ((i == k) | (j == l));
                }
            }
        }
    }
    auto ans = gauss_elim(eq, b, p);
    if(ans[0] == -1) {
      cout << -1 << endl;
      return;
    }
    int k = accumulate(ans.begin(), ans.end(), 0);
    cout<<k<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            assert(ans[i*m + j] >= 0 && ans[i*m + j] < p);
            while(ans[i*m + j]--){
                cout<<i*m + j + 1<<"\n";
            }
        }
    }
}

int main() {
  solve();
}