#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

int n, sz;
vector<int> lis, arr, poss[maxN], inv, ans, output;
multiset<int> lengths;

set<pii> segs;

inline void add(int p){
    auto seg = --segs.lower_bound({p, maxN});
    int l = seg->F, r = seg->S;
    segs.erase(seg);
    lengths.erase(lengths.lower_bound(r - l + 1));

    pii newL = {l, p - 1}, newR = {p + 1, r};
    if(l <= p - 1){
        segs.insert(newL);
        lengths.insert(newL.S - newL.F + 1);
    }
    if(p + 1 <= r){
        segs.insert(newR);
        lengths.insert(newR.S - newR.F + 1);
    }
}

int main(){
    ericxiao;
    cin >> n;
    arr.resize(n);
    lis.resize(n);
    ans.resize(n);
    output.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        lis[i] = arr[i];
    }
    sort(lis.begin(), lis.end());
    sz = unique(lis.begin(), lis.end()) - lis.begin();
    inv.resize(sz + 1);
    for(int i = 0; i < sz; i++){
        inv[i + 1] = lis[i];
    }
    for(int i = 0; i < n; i++){
        arr[i] = upper_bound(lis.begin(), lis.begin() + sz, arr[i]) - lis.begin();
        poss[arr[i]].push_back(i);
    }
    segs.insert({0, n - 1});
    lengths.insert(n);
    int tp;
    for(int i = 1; i <= sz; i++){
        if(!lengths.size()) break;
        tp = *lengths.rbegin();
        ans[tp]++;
        for(int p : poss[i]){
            add(p);
        }

    }
    int cans = 0;
    for(int i = n; i >= 1; i--){
        cans += ans[i];
        output[i] = cans;
    }
    for(int i = 1; i <= n; i++){
        cout << inv[output[i]] << " \n"[i == n];
    }
}



