#pragma GCC optimize ("O3")
#include <iostream>
#include <vector>
#include <queue>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int unsigned long long int
using namespace std;

const int maxN = 3e5, maxM = 3e5, maxQ = 3e5;
int bit[maxM + 10], need[maxN + 10], has[maxN + 10], ans[maxN + 10], comp[maxM + 10], N, M, Q, ll, rr, mm;
vector<int> indexes[maxN + 10];

inline void mod(int p, int x){
    for(int i = p; i <= M; i += (i & -i)){
        bit[i] += x;
    }
}

inline int get(int p){
    int res = 0;
    for(int i = p; i > 0; i -= (i & -i)){
        res += bit[i];
    }
    return res;
}

inline void add(int l, int r, int v){ //add the value v to range [l, r]
    if(l <= r){
        mod(l, v);
        mod(r + 1, -v);
    } else {
        mod(1, v);
        mod(r + 1, -v);
        mod(l, v);
    }
}

struct OP{
    int l, r, m;
    OP(){}
    OP(int ll, int rr, int mm): l(ll), r(rr), m(mm){}
} ops[maxM + 10];

struct Query{
    vector<int> v;
    int l, r;
    Query(){}
    Query(int ll, int rr, vector<int> vv): l(ll), r(rr), v(vv){}
};

signed main(){
    ericxiao;
    cin >> N >> M;
    for(int i = 1; i <= M; ++i){
        cin >> comp[i];
        indexes[ comp[i] ].push_back(i);
    }
    for(int i = 1; i <= N; ++i){
        cin >> need[i];
        ans[i] = -1;
    }
    cin >> Q;
    for(int i = 1; i <= Q; ++i){
        cin >> ll >> rr >> mm;
        ops[i] = OP(ll, rr, mm);
    }
    queue<Query> que;
    vector<int> vec;
    vec.clear();
    for(int i = 1; i <= N; ++i) vec.push_back(i);
    que.push(Query(1, Q + 2, vec));
    Query q;

    int lastl = 1;

    while(que.size()){
        q = que.front();
        que.pop();
        //cout << "Running: L = " << q.l << ", R = " << q.r << ", Ns: ";
        //for(int u : q.v) cout << u << " ";
        //cout << endl;
        if(q.l + 1 == q.r){
            for(int u : q.v) ans[u] = q.l;
            continue;
        }
        int m = (q.l + q.r) / 2;
        if(lastl > m){
            //cout << "Reset" << endl;
            fill(bit, bit + M + 1, 0);
            lastl = 1;
        }
        //cout << "Running all operations up to, but not including " << m << endl;
        while(lastl < m){
            //cout << "Running f(" << lastl << ")" << endl;
            add(ops[lastl].l, ops[lastl].r, ops[lastl].m);
            ++lastl;
        }

        for(int u : q.v){
            has[u] = 0;
            for(int c : indexes[u]){
                has[u] += get(c);
            }
        }

        vector<int> left, right;

        for(int u : q.v){
            //cout << "The company " << u << " has " << has[u] << " meteors" << endl;
            if(has[u] >= need[u]) left.push_back(u);
            else right.push_back(u);
        }
        //cout << "lastl = " << lastl << endl;
        que.push(Query(q.l, m, left));
        que.push(Query(m, q.r, right));
    }
    for(int i = 1; i <= N; ++i){
        if(ans[i] == Q + 1){
            cout << "NIE" << endl;
        } else {
            cout << ans[i] << endl;
        }
    }
}
