#pragma GCC optimize ("O3")
#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 226;

int N, M, movie[maxN], like[maxN], p[maxN], pat[maxN];
long long int seg[maxN * 4], tag[maxN * 4], ans;

inline void push(int id, int l, int r){
    seg[id] += tag[id];
    if(l + 1 < r){
        tag[2 * id + 1] += tag[id];
        tag[2 * id + 2] += tag[id];
    }
    tag[id] = 0;
}

inline void pull(int id){
    seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
}

void modify(int id, int ql, int qr, int v, int l = 1, int r = N + 1){
    push(id, l, r);
    if(ql >= r || l >= qr) return;
    if(ql <= l && r <= qr){
        tag[id] += v;
        push(id, l, r);
        return;
    }
    int m = (l + r) / 2;
    modify(2 * id + 1, ql, qr, v, l, m);
    modify(2 * id + 2, ql, qr, v, m, r);
    pull(id);
}

int query(int id, int ql, int qr, int l = 1, int r = N + 1){
    push(id, l, r);
    if(ql >= r || l >= qr) return -1;
    if(ql <= l && r <= qr) return seg[id];
    int m = (l + r) / 2;
    return max(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
}


signed main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> movie[i];
    for(int i = 1; i <= M; i++) cin >> like[i];
    for(int i = 1; i <= N; i++){
        p[i] = pat[movie[i]];
        pat[movie[i]] = i;
    }
    for(int i = 1; i <= N; i++){
        modify(0, p[i] + 1, i + 1, like[movie[i]]);
        modify(0, p[p[i]] + 1, p[i] + 1, -like[movie[i]]);
        push(0, 0, maxN);
        ans = max(ans, seg[0]);
    }
    cout << ans << '\n';
}
