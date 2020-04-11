#include <iostream>
#include <vector>
#include <algorithm>
#define ALL(x) x.begin(),x.end()
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 226, maxNodes = 5e6 + 226;

int N, x, seg[maxNodes], l[maxNodes], r[maxNodes], roots[maxN], cnt = 1, stk[300], arr[maxN], ans;
vector<int> lisan;
int newNode(){
    return cnt++;
}

void pull(int id){
    seg[id] = max(seg[l[id]], seg[r[id]]);
}

void build(int id, int L = 0, int R = maxN){
    if(L + 1 == R) return;
    l[id] = newNode();
    r[id] = newNode();
    int M = (L + R) / 2;
    build(l[id], L, M);
    build(r[id], M, R);
}

int modify(int o, int p, int v){
    int L = 0, R = maxN, M, res = newNode(), rt = res, ct = 0;
    while(L + 1 < R){
        M = (L + R) / 2;
        if(p < M){
            r[rt] = r[o];
            l[rt] = newNode();
            stk[ct++] = rt;
            rt = l[rt];
            o = l[o];
            R = M;
        } else {
            r[rt] = newNode();
            l[rt] = l[o];
            stk[ct++] = rt;
            rt = r[rt];
            o = r[o];
            L = M;
        }
    }
    seg[rt] = max(seg[rt], v);
    for(int i = ct - 1; i >= 0; i--) pull(stk[i]);
    return res;
}

int query(int id, int ql, int qr, int L = 0, int R = maxN){
    //cout << "id = " << id << endl;
    //cout << "Running query of " << ql << ", " << qr << "cur: " << L << ", " << R << endl;
    if(L >= qr || ql >= R) return -1;
    if(ql <= L && R <= qr) return seg[id];
    int m = (L + R) / 2;
    return max(query(l[id], ql, qr, L, m), query(r[id], ql, qr, m, R));
}

void disp(int r){
    for(int i = 0; i < 6; i++){
        cout << query(r, i, i + 1) << " ";
    }
    cout << endl;
}

struct ZCK{
    int sg[maxN * 2];
    void modify(int p, int v){
        p += maxN;
        sg[p] = max(sg[p], v);
        for(; p; p >>= 1) sg[p >> 1] = max(sg[p], sg[p ^ 1]);
    }
    int query(int l, int r){
        int res = 0;
        for(l += maxN, r += maxN; l < r; l >>= 1, r >>= 1){
            if(l & 1) res = max(res, sg[l++]);
            if(r & 1) res = max(res, sg[--r]);
        }
        return res;
    }
} rmq;

void zckdisp(){
    for(int i = 0; i < 6; i++){
        cout << rmq.query(i, i + 1) << " ";
    }
    cout << endl;
}

int main(){
    ericxiao;
    cin >> N >> x;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        lisan.push_back(arr[i]);
    }
    sort(ALL(lisan));
    int sz = unique(ALL(lisan)) - lisan.begin();
    for(int i = 0; i < N; i++) arr[i] = lower_bound(lisan.begin(), lisan.begin() + sz, arr[i]) - lisan.begin();
    roots[N] = newNode();
    build(roots[N]);
    int mv;
    for(int i = N - 1; i >= 0; i--){ //remember to lisanhua
        mv = query(roots[i + 1], arr[i] + 1, maxN) + 1;
        roots[i] = modify(roots[i + 1], arr[i], mv);
    }
    for(int i = 0; i < N; i++){
        mv = rmq.query(0, arr[i]) + 1;
        //cout << "LIS of " << i << " is " << mv << endl;
        rmq.modify(arr[i], mv);
        int lq = upper_bound(lisan.begin(), lisan.begin() + sz, lisan[arr[i]] - x) - lisan.begin();
        ans = max(ans, mv + query(roots[i + 1], lq, maxN));
        //cout << endl;
    }
    cout << ans << '\n';
}
