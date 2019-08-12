#include <iostream>
#include <queue>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);
#define int long long int
using namespace std;

const int maxN = 2e5;

int seg[maxN << 2], tag[maxN << 2], arr[maxN + 10], N;

void build(int id = 0, int l = 0, int r = N){
    if(l + 1 == r){
        seg[id] = arr[l];
        tag[id] = 0;
        return;
    }
    build(2 * id + 1, l, (l + r)/2);
    build(2 * id + 2, (l + r)/2, r);
    seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

void push(int id, int l, int r){
    if(tag[id] != 0){
        seg[id] += (r - l) * tag[id];
        if(l + 1 < r){
            tag[2 * id + 1] += tag[id];
            tag[2 * id + 2] += tag[id];
        }
        tag[id] = 0;
    }
}

void modify(int id, int l, int r, int ql, int qr, int k){
    push(id, l, r);
    if(qr <= l || ql >= r) return;
    if(ql <= l && r <= qr){
        tag[id] += k;
        push(id, l, r);
        return;
    }
    modify(2 * id + 1, l, (l + r) / 2, ql, qr, k);
    modify(2 * id + 2, (l + r) / 2, r, ql, qr, k);
    seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

int query(int id, int l, int r, int ql, int qr){
    push(id, l, r);
    if(qr <= l || ql >= r) return 0;
    if(ql <= l && r <= qr){
        return seg[id];
    }
    return query(2 * id + 1, l, (l + r) / 2, ql, qr) + query(2 * id + 2, (l + r) / 2, r, ql, qr);
}

int c, a, b, q, d;

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
        build(0, 0, N);

    cin >> q;
    while(q--){
        cin >> c;
        if(c){
            cin >> a >> b;
            cout << query(0, 0, N, a, b) << endl;
        } else {
            cin >> a >> b >> d;
            modify(0, 0, N, a, b, d);
        }
    }
}
