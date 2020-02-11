#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 226;

int N, Q, L, R, lastpos[maxN], arr[maxN], point[maxN];


struct RMQ{
    int seg[maxN * 4];
    RMQ(){
        fill(seg, seg + 4 * N, 0);
    }
    inline void pull(int id){
        seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
    }
    void build(int id = 0, int l = 0, int r = N + 1){
        if(l + 1 == r){
            seg[id] = point[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * id + 1, l, m);
        build(2 * id + 2, m, r);
        pull(id);
    }
    void modify(int id, int l, int r, int pos, int v){
        if(l + 1 == r){
            seg[id] = v;
            return;
        }
        int m = (l + r) / 2;
        if(pos < m) modify(2 * id + 1, l, m, pos, v);
        else modify(2 * id + 2, m, r, pos, v);
    }
    int query(int id, int l, int r, int ql, int qr){
        if(ql >= r || l >= qr) return 0;
        if(ql <= l && r <= qr) return seg[id];
        int m = (l + r) / 2;
        return max(query(2 * id + 1, l, m, ql, qr), query(2 * id + 2, m, r, ql, qr));
    }
} rmq;


int main(){
    ericxiao;
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        if(!lastpos[arr[i]]) point[i] = -1;
        else point[i] = lastpos[arr[i]];
        lastpos[arr[i]] = i;
    }
    rmq.build();
    //cout << "Fin build" << endl;
    while(Q--){
        cin >> R;
        int l = 0, r = R, m;
        while(l + 1 < r){
            m = (l + r) / 2;
            //cout << "Checkign for " << m << endl;
            //cout << "far: " << rmq.query(0, 0, N + 1, m, R + 1) << endl;
            if(rmq.query(0, 0, N + 1, m, R + 1) >= m){
                l = m;
            } else r = m;
            //cout << "l = " << l << ", r = " << r << endl;
        }
        cout << r << '\n';
    }
}
