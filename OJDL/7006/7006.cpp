#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e6;

int seg[maxN*4 + 10], ls[4 * maxN + 10], rs[4 * maxN + 10], head = 0, vers[maxN], inv[maxN];

inline void pull(int id){
    seg[id] = seg[ls[id]] + seg[rs[id]];
}

int build(int l, int r){
    //cout << "The segment corresponding to " << l << ", " << r << " has id "  << head << endl;
    int newId = head;
    head++;
    if(l + 1 == r){
        seg[newId] = 0;
        return newId;
    }
    int m = (l + r) / 2;
    ls[newId] = build(l, m);
    rs[newId] = build(m, r);
    return newId;
}

int add(int id, int l, int r, int pos){
    //cout << "The range " << l << " to " << r << " has id " << head << endl;
    int newId = head;
    head++;
    if(l + 1 == r){
        seg[newId] = seg[id] + 1;
        return newId;
    }
    int m = (l + r) / 2;
    if(pos < m){
        ls[newId] = add(ls[id], l, m, pos);
        rs[newId] = rs[id];
    } else {
        ls[newId] = ls[id];
        rs[newId] = add(rs[id], m, r, pos);
    }
    pull(newId);
    return newId;
}

int getKth(int id1, int id2, int l, int r, int k){
    //cout << " getting " << k << "th of numbers between " << l << " and " << r << endl;
    if(l + 1 == r){
        return l;
    }
    int m = (l + r) / 2;
    int b = seg[ls[id2]] - seg[ls[id1]];
    if(b >= k){
        return getKth(ls[id1], ls[id2], l, m, k);
    } else {
        return getKth(rs[id1], rs[id2], m, r, k - b);
    }
}

int N, M, l, r, k, x;
vector<int> lis, vals;
signed main(){
    ericxiao;
    cin >> N >> M;
    vals.resize(N);
    lis.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vals[i];
        lis[i] = vals[i];
    }
    sort(lis.begin(), lis.end());
    unique(lis.begin(), lis.end());
    int r;
    for(int i = 0; i < N; i++){
        r = lower_bound(lis.begin(), lis.end(), vals[i]) - lis.begin();
        inv[r] = vals[i];
        vals[i] = r;
    }
    /*
    for(int i = 0; i < N; i++){
        cout << vals[i] << " ";
    }
    cout << endl;
    */
    vers[0] = build(0, N);
    for(int i = 1; i <= N; i++){
        //cout << "Modifying the place " << vals[i - 1] << endl;
        vers[i] = add(vers[i - 1], 0, N, vals[i - 1]);
    }
    for(int i = 0; i < M; i++){
        cin >> l >> r >> k;
        k = (r - l + 2 - k);
        //cout << "The " << k << "th largest" << endl;
        cout << inv[getKth(vers[l - 1], vers[r], 0, N, k)] << endl;
    }
}
