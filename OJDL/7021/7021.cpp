#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 5, INF = 1e9;

int seg[maxN * 4], arr[maxN], maxval[maxN * 4];
bool tag[maxN * 4];

void pull(int id){
    seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
    maxval[id] = max(maxval[2 * id + 1], maxval[2 * id + 2]);
}

void build(int id, int l, int r){
    if(l + 1 == r){
        seg[id] = arr[l];
        maxval[id] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    pull(id);
}

void modify(int id, int ql, int qr, int l, int r, int c){
    if(qr <= l || ql >= r) return;
    if(ql <= l && r <= qr && maxval[id] < c) return;
    if(l + 1 == r){
        seg[id] %= c;
        maxval[id] = seg[id];
        return;
    }
    int m = (l + r) / 2;
    modify(2 * id + 1, ql, qr, l, m, c);
    modify(2 * id + 2, ql, qr, m, r, c);
    pull(id);
}

int query(int id, int ql, int qr, int l, int r){
    if(qr <= l || ql >= r) return 0;
    if(ql <= l && r <= qr){
        return seg[id];
    }
    int m = (l + r) / 2;
    return query(2 * id + 1, ql, qr, l, m) + query(2 * id + 2, ql, qr, m, r);
}

int n, m, cm, l, r, k;

signed main(){
    ericxiao;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(0, 0, n);
    for(int i = 0; i < m; i++){
        cin >> cm >> l >> r;
        if(cm == 1){
            cin >> k;
            modify(0, l, r + 1, 0, n, k);
        } else if(cm == 2){
            cout << query(0, l, r + 1, 0, n) << endl;
        }
    }
}

