#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 1e5;
int seg[3*MAX + 2], arg1, arg2, N, Q, arr[MAX + 4], t;
char com;

int sgn(int n){
    return ((n) ? ((n > 0) ? 1 : -1) : 0);
}

void build(int id, int l, int r){
    if(l + 1 == r){
        seg[id] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id + 1, l, mid);
    build(2 * id + 2, mid, r);
    seg[id] = seg[2 * id + 1] * seg[2 * id + 2];
}

int query(int id, int ql, int qr, int l, int r){
    if(ql >= r || qr <= l) return 1;
    if(ql <= l && r <= qr) return seg[id];
    int mid = (l + r)/2;
    return query(2 * id + 1, ql, qr, l, mid) * query(2 * id + 2, ql, qr, mid, r);
}

void modify(int id, int val, int pos, int l, int r){
    //printf("Running modify: id = %d, val = %d, pos = %d, l = %d, r = %d\n", id, val, pos, l, r);
    if(l + 1 == r) {
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos < mid) modify(2*id + 1, val, pos, l, mid);
    else modify(2 * id + 2, val, pos, mid, r);
    seg[id] = seg[2 * id + 1] * seg[2 * id + 2];
}


int main(){
    while(cin >> N >> Q){
        for(int i = 0; i < N; i++){
            cin >> t;
            arr[i] = sgn(t);
        }
        build(0, 0, N);
        string ans = "";
        while(Q--){
            cin >> com >> arg1 >> arg2;
            if(com == 'C'){
                modify(0, sgn(arg2), arg1-1, 0, N);
            } else {
                int res = query(0, arg1-1, arg2, 0, N);
                if(res == 1){
                    ans += '+';
                } else if (res == 0){
                    ans += '0';
                } else {
                    ans += '-';
                }
            }
        }
        cout << ans << endl;
    }
}
