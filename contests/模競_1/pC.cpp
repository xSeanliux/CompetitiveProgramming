#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

struct Doll{
    int h, w, f, id;
    Doll(){}
    Doll(int H, int W, int F, int ID): h(H), w(W), f(F), id(ID){}
    bool operator<(const Doll d) const {
        return (d.h == h ? w > d.w : h < d.h);
    }
} dolls[maxN];

int n, q, h, w, f, x, dp[maxN], dp2[maxN], seg[maxN * 4];

int query(int id, int ql, int qr, int l, int r){
    if(ql >= r || qr <= l)
        return 0;
    if(ql <= l && r <= qr) return seg[id];
    int m = (l + r) / 2;
    return max(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
}

void modify(int id, int l, int r, int pos, int val){
    if(l + 1 == r){
        seg[id] = max(seg[id], val);
        return;
    }
    int m = (l + r) / 2;
    if(pos < m) modify(2 * id + 1, l, m, pos, val);
    else modify(2 * id + 2, m, r, pos, val);
    seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
}

signed main(){
    ericxiao;
    cin >> n >> q;
    vector<int> lis;
    for(int i = 0; i < n; i++){
        cin >> h >> w >> f;
        lis.push_back(w);
        dolls[i] = Doll(h, w, f, i);
    }
    sort(lis.begin(), lis.end());
    unique(lis.begin(), lis.end());
    sort(dolls, dolls + n);

    for(int i = 0; i < n; i++){
        dolls[i].w = lower_bound(lis.begin(), lis.end(), dolls[i].w) - lis.begin();
    }
    for(int i = 0; i < n; i++){
        //cout << dolls[i].h << " " << dolls[i].w << " " << dolls[i].f << endl;
    }
    fill(seg, seg + 4 * n, 0);
    for(int i = 0; i < n; i++){
        dp[i] = query(0, 0, dolls[i].w, 0, n) + dolls[i].f;
        //cout << "dp[" << i << "] = " << dp[i] << endl;
        modify(0, 0, n, dolls[i].w, dp[i]);
    }
    fill(seg, seg + 4 * n, 0);
    for(int i = n - 1; i >= 0; i--){
        dp2[i] = query(0, dolls[i].w + 1, n, 0, n) + dolls[i].f;
        //cout << "dp2[" << i << "] = " << dp[i] << endl;
        modify(0, 0, n, dolls[i].w, dp2[i]);
    }
    int inv[maxN];
    for(int i = 0; i < n; i++) inv[dolls[i].id] = i;
    while(q--){
        cin >> x;
        x--;
        x = inv[x];
        cout << dp2[x] + dp[x] - dolls[x].f << endl;
    }
}
