#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, blockSize = 500, maxC = (1LL << 23);

int n, m, k, q, l, r, ca, frq[maxC], L, R;

struct Que{
    int l, r, id;
    Que(){}
    Que(int L, int R, int I): l(L), r(R), id(I){}
    bool operator<(const Que q) const {
        return (l/blockSize == q.l/blockSize) ? r < q.r : l/blockSize < q.l/blockSize;
    }
};

vector<Que> queries;
vector<int> pre, ans;

inline void add(int pos){
    ca += frq[pre[pos] ^ k];
    frq[pre[pos]]++;
}

inline void del(int pos){
    frq[pre[pos]]--;
    ca -= frq[pre[pos] ^ k];
}

signed main(){
    ericxiao;
    cin >> n >> m >> k;
    pre.resize(n + 1);
    ans.resize(m);
    queries.resize(m);
    pre[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> pre[i];
        pre[i] ^= pre[i - 1];
    }
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        queries[i] = Que(l - 1  , r, i);
    }
    sort(queries.begin(), queries.end());
    L = 0, R = 0, ca = 0;
    frq[0]++;
    for(Que q : queries){
        while(L > q.l) add(--L);
        while(R < q.r) add(++R);
        while(L < q.l) del(L++);
        while(R > q.r) del(R--);
        ans[q.id] = ca;
    }
    for(int u : ans) cout << u << " ";
    cout << endl;
}
