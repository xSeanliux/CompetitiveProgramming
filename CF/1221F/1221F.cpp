#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <tuple>
#define pii pair<int, int>
#define F first
#define S second
#define int long long int
#define tup tuple<int, int, int> //max, min, cost
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e5 + 10, INF = 1e16;
int n, cnt = 0, ans = 0, x, y, c, ll = 2e9, rr = 2e9;
int seg[maxN << 2], tag[maxN << 2], maxFrom[maxN << 2];

vector<tup> vec;
vector<int> lismin;

inline void pull(int id){
    if(seg[2 * id + 1] >= seg[2 * id + 2]){
        maxFrom[id] = maxFrom[2 * id + 1];
    } else {
        maxFrom[id] = maxFrom[2 * id + 2];
    }
    seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
}

void build(int id, int l, int r){
    seg[id] = 0;
    if(l + 1 == r){
        maxFrom[id] = lismin[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    pull(id);
}

inline void push(int id, int l, int r){
    seg[id] += tag[id];
    if(l + 1 < r){
        tag[2 * id + 1] += tag[id];
        tag[2 * id + 2] += tag[id];
    }
    tag[id] = 0;
}

void modify(int id, int ql, int qr, int l, int r, int v){
    push(id, l, r);
    if(qr <= l || ql >= r) return;
    if(ql <= l && r <= qr){
        tag[id] += v;
        push(id, l, r);
        return;
    }
    int m = (l + r) / 2;
    modify(2 * id + 1, ql, qr, l, m, v);
    modify(2 * id + 2, ql, qr, m, r, v);
    pull(id);
}

pii query(int id, int ql, int qr, int l, int r){
    push(id, l, r);
    if(qr <= l || ql >= r) return pii(-INF, -1);
    if(ql <= l && r <= qr) return pii(seg[id], maxFrom[id]);
    int m = (l + r) / 2;
    pii a, b;
    return max(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
}


signed main(){
    ericxiao;
    cin >> n;
    vec.resize(n);
    for(int i = 0; i < n; i++){
        cin >> x >> y >> c;
        if(x < y) swap(x, y);
        vec[i] = make_tuple(x, y, c);
        lismin.push_back(y);
    }
    sort(lismin.begin(), lismin.end());
    int minsz = unique(lismin.begin(), lismin.end()) - lismin.begin();

    sort(vec.begin(), vec.end(), [](const tup a, const tup b) {
        return (get<0>(a) == get<0>(b)) ? get<1>(a) > get<1>(b) : get<0>(a) < get<0>(b);
    });

    int cm, re;
    bool modified[minsz + 10];
    pii res;
    build(0, 0, minsz);
    fill(modified, modified + minsz + 5, false);
    for(int i = 0; i < n; i++){
        cm = get<0>(vec[i]);
        re = upper_bound(lismin.begin(), lismin.begin() + minsz, get<1>(vec[i])) - lismin.begin();
        modify(0, 0, re, 0, minsz, get<2>(vec[i]));
        if(!modified[re - 1]){
            modify(0, re - 1, re, 0, minsz, get<1>(vec[i]));
            modified[re - 1] = true;
        }
        if(i < n - 1 && get<0>(vec[i]) == get<0>(vec[i + 1])) continue;
        res = query(0, 0, re, 0, minsz);
        //cout << "Max stuff with indx " << get<0>(vec[i]) << ", " << get<1>(vec[i]) << " is " << res.F - get<0>(vec[i]) << endl;
        if(ans < res.F - get<0>(vec[i])){
            ans = res.F - get<0>(vec[i]);
            ll = res.S;
            rr = get<0>(vec[i]);
        }
    }
    cout << ans << endl;
    cout << ll << " " << ll << " " << rr << " " << rr << endl;
}

