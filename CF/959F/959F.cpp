#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxC = (1 << 21) + 5, maxN = 1e5 + 22625, MOD = 1e9 + 7;

struct Que{
    int l, x, ind;
    Que(){}
    Que(int L, int X, int I): l(L), x(X), ind(I){}
};

int reachable[maxC], arr[maxN], n, q, ans[maxN], l, x, basisCnt = 1;
Que ques[maxN];

inline void add(int x){
    if(!reachable[x]){
        basisCnt++;
        for(int i = 0; i < maxC; i++){
            if(reachable[i] && ((i ^ x) < maxC)) reachable[i ^ x] = true;
        }
    }
}

int modexp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = modexp(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

signed main(){
    ericxiao;
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < q; i++){
        cin >> ques[i].l >> ques[i].x;
        ques[i].l--;
        ques[i].ind = i;
    }
    sort(ques, ques + q, [](const Que a, const Que b) { return a.l < b.l; });
    fill(reachable, reachable + maxC, false);
    reachable[0] = true;
    int ci = 0;
    Que cq;
    for(int i = 0; i < q; i++){
        cq = ques[i];
        while(cq.l >= ci){ //add number in
            add(arr[ci++]);
        }
        if(!reachable[cq.x]) ans[cq.ind] = 0;
        else ans[cq.ind] = modexp(2, 2 + cq.l - basisCnt);
    }
    for(int i = 0; i < q; i++) cout << ans[i] << '\n';
}
