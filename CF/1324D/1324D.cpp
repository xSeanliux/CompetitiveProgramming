#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 2e5 + 26;

int a[maxN], b[maxN], N, ans = 0, sz, bit[maxN * 2];
vector<int > lisan;

inline void modify(int p){
    for(; p < maxN * 2; p += (p & -p)) bit[p]++;
}

inline int query(int p){
    int r = 0;
    for(; p; p -= (p & -p)) r += bit[p];
    return r;
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    for(int i = 0; i < N; i++){
        lisan.push_back(a[i] - b[i]);
        lisan.push_back(b[i] - a[i]);
    }
    sort(lisan.begin(), lisan.end());
    int sz = unique(lisan.begin(), lisan.end()) - lisan.begin();
    for(int i = 0; i < N; i++){
        ans += query(lower_bound(lisan.begin(), lisan.begin() + sz, a[i] - b[i]) - lisan.begin() + 1);
        modify(lower_bound(lisan.begin(), lisan.begin() +sz, b[i] - a[i]) - lisan.begin() + 2);
    }
    cout << ans << endl;
}
