#include <iostream>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 226, maxLog = 20;
int N, Q, l, r, pos[maxN], hei[maxN];
pii jump[maxN][maxLog];

struct RMQ{
    int seg[maxN * 4];
    RMQ(){
        fill(seg, seg + 4 * maxN, 0);
    }
    inline void pull(int id){
        seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
    }
    int query(int ql, int qr, int id = 0, int l = 0, int r = N + 2){
        if(ql >= r || l >= qr) return 0;
        if(ql <= l && r <= qr) return seg[id];
        int m = (l + r) / 2;
        return max(query(ql, qr, 2 * id + 1, l, m), query(ql, qr, 2 * id + 2, m, r));
    }
    void modify(int pos, int x, int id = 0, int l = 0, int r = N + 2){
        if(l + 1 == r){
            seg[id] = x;
            return;
        }
        int m = (l + r) / 2;
        if(pos < m)
            modify(pos, x, 2 * id + 1, l, m);
        else modify(pos, x, 2 * id + 2, m, r);
        pull(id);
    }
};

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> pos[i] >> hei[i];
    pos[N + 1] = 2e10;
    RMQ rmq = RMQ();
    for(int i = 0; i < maxLog; i++) jump[N + 1][i] = {N + 1, 0};
    for(int i = N; i; i--){
        int oneshot = upper_bound(pos + 1, pos + N + 2, pos[i] + hei[i]) - pos;
        int maxRange = max(pos[i] + hei[i], rmq.query(i, oneshot));
        rmq.modify(i, maxRange);
        if(maxRange >= pos[N]){
            jump[i][0] = {N + 1, 0};
        } else {
            int ind = upper_bound(pos + 1, pos + N + 2, maxRange) - pos;
            jump[i][0] = {ind, pos[ind] - maxRange};
        }
        for(int j = 1; j < maxLog; j++){
            jump[i][j].F = jump[jump[i][j - 1].F][j - 1].F;
            jump[i][j].S = jump[i][j - 1].S + jump[jump[i][j - 1].F][j - 1].S;
        }
        //cout << "M" << i << endl;
    }
    cin >> Q;
    int cnt = 0;
    while(Q--){
        cnt++;
        cin >> l >> r;
        int cost = 0;
        for(int d = maxLog - 1; d >= 0; d--){
            if(jump[l][d].F <= r){
                cost += jump[l][d].S;
                l = jump[l][d].F;
                break;
            }
        }
        cout << cost << endl;
    }
}
