#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse2,sse3,avx")
//#include <ext/pb_ds/assoc_container.hpp>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#define ll long long int
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
//using namespace __gnu_pbds;
const ll B = 101, P = 998244353, maxN = 5e5 + 10;

vector<string> strings;
set<int> lens;
int N, Q, l[maxN], r[maxN], k[maxN], ord[maxN], ans[maxN];

unordered_map<ll, vector<int> > mp;

ll bp[maxN];
vector<ll> hsh[maxN];

inline ll sub(ll a, ll b) {
  return a >= b ? a - b : a - b + P;
}

void getHsh(int id) {
  hsh[id].resize(strings[id].length());
  hsh[id][0] = strings[id][0];
  for(int i = 1; i < strings[id].length(); i++) hsh[id][i] = (hsh[id][i - 1] * B % P + strings[id][i]) % P;
}

signed main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  bp[0] = 1;
  //mp.reserve(maxN * 5);
  for(int i = 1; i < maxN; i++) bp[i] = bp[i - 1] * B % P;

  cin >> N >> Q;
  strings.resize(N);
  for(int i = 0; i < N; i++) {
    cin >> strings[i];
    lens.insert(strings[i].length());
    getHsh(i);
  }
  for(auto &[k, s] : mp) {
    sort(s.begin(), s.end());
  }
  for(int i = 0; i < Q; i++) {
    ord[i] = i;
    cin >> l[i] >> r[i] >> k[i];
    l[i]--;
    r[i]--;
    k[i]--;
  }
  sort(ord, ord + Q, [](int a, int b){
    return strings[k[a]].length() < strings[k[b]].length();
  });
  for(int i = 0; i < Q; i++) {
    if(!i || strings[k[ord[i]]].length() != strings[k[ord[i - 1]]].length()) { //remake map
      int l = strings[k[ord[i]]].length();
      //cout << "k = " << k[ord[i]] << endl;
      //cout << "remaking map with l = " << l << endl;
      mp = unordered_map<ll, vector<int> >();
      mp.reserve(maxN * 10);
      for(int ii = 0; ii < N; ii++) {
        for(int j = l - 1; j < strings[ii].length(); j++) {
          ll hshval = (j == l - 1 ? hsh[ii][j] : sub(hsh[ii][j], hsh[ii][j - l] * bp[l] % P));
          if(!mp.count(hshval)) mp[hshval] = vector<int>();
          mp[hshval].push_back(ii);
        }
      }
    }
    
    ll hshval = hsh[k[ord[i]]][strings[k[ord[i]]].length() - 1];
    int countR = upper_bound(mp[hshval].begin(), mp[hshval].end(), r[ord[i]]) - mp[hshval].begin();
    int countL = upper_bound(mp[hshval].begin(), mp[hshval].end(), l[ord[i]] - 1) - mp[hshval].begin();
    ans[ord[i]] = countR - countL;
  }
  for(int i = 0; i < Q; i++) cout << ans[i] << '\n';
}