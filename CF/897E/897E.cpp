#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

struct Seg{
    int l, r;
    mutable int v;
    Seg(int ll, int rr = -1, int vv = 0): l(ll), r(rr), v(vv){}
    bool operator<(const Seg& o) const {
        return l < o.l;
    }
};

int rnd();
int pow(int b, int e);

set<Seg> st;

set<Seg>::iterator split(int pos){
    auto it = st.lower_bound(Seg(pos));
    if(it != st.end() && it->l == pos) return it;
    --it;
    if(pos >= it->r) return st.end();
    int L = it->l, R = it->r, V = it->v;
    st.erase(it);
    st.insert(Seg(L, pos, V));
    return st.insert(Seg(pos, R, V)).first;
}

void add(int l, int r, int val){
    split(l), split(r);
    auto il = st.lower_bound(Seg(l)), ir = st.lower_bound(Seg(r));
    for(; il != ir; ++il){
        il->v += val;
    }
}

void flat(int l, int r, int val){
    split(l), split(r);
    auto il = st.lower_bound(Seg(l)), ir = st.lower_bound(Seg(r));
    int L = il->l, R = ir->r;
    st.erase(il, ir);
    st.insert(Seg(l, r, val));
}

int getkth(int l, int r, int x){
    vector<pii> v;
    split(l), split(r);
    auto il = st.lower_bound(Seg(l)), ir = st.lower_bound(Seg(r));
    for(; il != ir; il++){
        v.push_back({il->v, (il->r - il->l)});
    }
    sort(v.begin(), v.end());
    int k = x;
    for(pii p : v){
        k -= p.S;
        if(k <= 0) return p.F;
    }
    return -1;
}

int powsum(int l, int r, int x, int y){
    int ans = 0;
    split(l), split(r);
    auto il = st.lower_bound(Seg(l)), ir = st.lower_bound(Seg(r));
    for(; il != ir; il++){
        ans = (ans + pow(il->v % y, x) * (il->r - il->l) % y) % y;
    }
    return ans;
}

void disp(){
    for(auto s : st){
        printf("(%lld, %lld): %lld\n", s.l, s.r, s.v);
    }
    cout << endl;
}


int n, m, seed, vmax, a[100005], op, l, r, x, y, rxxx;

signed main(){
    cin >> n >> m >> seed >> vmax;
    for(int i = 1; i <= n; i++){
        a[i] = (rnd() % vmax) + 1;
        //cout << a[i] << " ";
    }
    //cout << endl;
    for(int i = 1; i <= n; i++){
        int r = i;
        while(r <= n && a[r] == a[i]){
            r++;
        }
        st.insert(Seg(i, r, a[i]));
        //cout << "Seg(" << i << ", " << r << ", " << a[i] << ")" << endl;
        i += (r - i) - 1;
    }

    for(int i = 0; i < m; i++){
        op = (rnd() % 4) + 1;
        l = (rnd() % n) + 1;
        r = (rnd() % n) + 1;
        if (l > r)
             swap(l, r);

        if(op == 3)
            x = (rnd() % (r - l + 1)) + 1;
        else
            x = (rnd() % vmax) + 1;

        if (op == 4)
            y = (rnd() % vmax) + 1;

        if(op < 4){
            //printf("%d %d %d %d\n", op, l, r, x);
        } else {
            //printf("%d %d %d %d %d\n", op, l, r, x, y);
        }
        if(op == 1){ //add x to a[l...r]
            add(l, r + 1, x);
        } else if(op == 2){ //set a[l...r] to x
            flat(l, r + 1, x);
        } else if(op == 3){ //get the xth smallest number in a[l...r]
            cout << getkth(l, r + 1, x) << '\n';
        } else if(op == 4){ //get the pow sum (exp x mod y)
            cout << powsum(l, r + 1, x, y) << '\n';
        }
        //disp();
    }
}

int pow(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = pow(b, e/2);
    res = res * res % y;
    if(e % 2) res = res * b % y;
    return res;
}

int rnd(){
    rxxx = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return rxxx;
}
