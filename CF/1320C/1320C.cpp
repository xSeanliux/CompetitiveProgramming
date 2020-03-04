#include <iostream>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxC = 1e6 + 10, maxN = 2e5 + 10, INF = 2e9;

int N, M, P, seg[maxC * 4], tag[maxC * 4], cnt, ans = -INF;

struct Monster{
    pii pos;
    int cost;
    Monster(){}
    const bool operator<(const Monster &m) const {
        return pos < m.pos;
    }
} monsters[maxN];

inline void pull(int id){
    seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
}

inline void push(int id, int l, int r){
    seg[id] += tag[id];
    if(l + 1 < r){
        tag[2 * id + 1] += tag[id];
        tag[2 * id + 2] += tag[id];
    }
    tag[id] = 0;
}

int query(int id, int ql, int qr, int l = 0, int r = maxC){
    push(id, l, r);
    if(r <= ql || qr <= l)
        return -INF;
    if(ql <= l && r <= qr)
        return seg[id];
    return max(query(2 * id + 1, ql, qr, l, (l + r) / 2), query(2 * id + 2, ql, qr, (l + r) / 2, r));
}

void modify(int id, int v, int ql, int qr, int l = 0, int r = maxC){
    push(id, l, r);
    if(r <= ql || qr <= l) return;
    if(ql <= l && r <= qr){
        tag[id] += v;
        push(id, l, r);
        return;
    }
    modify(2 * id + 1, v, ql, qr, l, (l + r) / 2);
    modify(2 * id + 2, v, ql, qr, (l + r) / 2, r);
    pull(id);
}

void addVal(int id, int v, int pos, int l = 0, int r = maxC){
    if(l + 1 == r){
        seg[id] = max(seg[id], v);
        return;
    }
    int m = (l + r) / 2;
    if(m > pos){
        addVal(2 * id + 1, v, pos, l, m);
    } else {
        addVal(2 * id + 2, v, pos, m, r);
    }
    pull(id);
}

pii xChoose[maxN], yChoose[maxN];
int main(){
    ericxiao;
    fill(seg, seg + maxC * 4, -INF);
    cin >> N >> M >> P;
    for(int i = 0; i < N; i++) cin >> xChoose[i].F >> xChoose[i].S;
    for(int i = 0; i < M; i++) cin >> yChoose[i].F >> yChoose[i].S;
    for(int i = 0; i < P; i++) cin >> monsters[i].pos.F >> monsters[i].pos.S >> monsters[i].cost;
    sort(xChoose, xChoose + N);
    sort(monsters, monsters + P);
    for(int i = 0; i < M; i++){
        addVal(0, -yChoose[i].S, yChoose[i].F);
    }

    for(int i = 0; i < N; i++){
        while(cnt < P && monsters[cnt].pos.F < xChoose[i].F){
            modify(0, monsters[cnt].cost, monsters[cnt].pos.S + 1, maxC);
            cnt++;
        }
        ans = max(ans, query(0, 0, maxC) - xChoose[i].S);
    }
    cout << ans << '\n';
}
