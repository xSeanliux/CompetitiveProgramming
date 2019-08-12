#include <iostream>
using namespace std;

const int maxN = 1e5;
int vals[maxN + 10], seg[4 * maxN], lazy[4 * maxN];

void push(int id, int l, int r){
    if(lazy[id]){
        seg[id] += (r - l) * lazy[id];
        if(l + 1 < r){ //if not leaf
            lazy[2 * id + 1] += lazy[id];
            lazy[2 * id + 2] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void pull(int id){
    seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

void build(int id, int l, int r){
    if(l + 1 == r){
        seg[id] = vals[l];
        return;
    }
    lazy[id] = 0;
    build(2 * id + 1, l, l + r >> 1);
    build(2 * id + 2, l + r >> 1, r);
    pull(id);
}

int query(int id, int ql, int qr, int l, int r){
    push(id, l, r);
    if(ql >= r || qr <= l) return 0;
    if(ql <= l && r <= qr){
        //remove lazy pointers
        push(id, l, r);
        return seg[id];
        //return ans
    } else {
        return query(2 * id + 1, ql, qr, l, l + r >> 1) + query(2 * id + 2, ql, qr, l + r >> 1, r);
    }
}

void upd(int id, int ql, int qr, int val, int l, int r){
    push(id, l, r);
    if(ql >= r || qr <= l) return;
    if(ql <= l && r <= qr){
        lazy[id] += val;
        push(id, l, r);
        return;
    }
    upd(2 * id + 1, ql, qr, val, l, l + r >> 1);
    upd(2 * id + 2, ql, qr, val, l + r >> 1, r);
    pull(id);
}

int N, l, r, k;
char c;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> vals[i];
    build(0, 0, N);
    while(cin >> c >> l >> r){
        if(c == 'q'){ //query
            cout << query(0, l - 1, r, 0, N);
        } else if(c == 'm') { //modify
            cin >> k;
            upd(0, l - 1, r, k, 0, N);
        }
    }
}
