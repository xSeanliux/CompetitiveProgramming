//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma GCC target("arch=core-avx2")
//#pragma GCC ivdep
#include <iostream>
#include <algorithm>
#include <utility>
#include <math.h>
#include <vector>
#include <set>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#define int long long int
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 10, INF = 1e10;

int x[maxN], N, K, D;

int seg[maxN << 2], tag[maxN << 2], maxes[maxN], mins[maxN], m1 = 0, m2 = 0;

void pull(int id) {
    seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
}

void push(int id, int l, int r) {
    if(!tag[id]) return;
    seg[id] += tag[id];
    if(r - l > 1) {
        tag[2 * id + 1] += tag[id];
        tag[2 * id + 2] += tag[id];
    }
    tag[id] = 0;
}

void modify(int id, int l, int r, int ql, int qr, int v) {
    push(id, l, r);
    if(ql >= r || l >= qr || seg[id] >= INF) return;
    //cout << "running mdf(" << id << ", " << l << ", " << r << ", " << ql << ", " << qr << ", " << v << ")" << endl;
    if(ql <= l && r <= qr) {
        tag[id] += v;
        push(id, l, r);
        //cout << "seg[" << id << "] = " << seg[id] << endl;
        return;
    }
    int m = (l + r) / 2;
    modify(2 * id + 1, l, m, ql, qr, v);
    modify(2 * id + 2, m, r, ql, qr, v);
    pull(id);
    //cout << "after pulling: seg[" << id << "] = " << seg[id] << endl;
}

int query(int id, int l, int r, int th) {
    push(id, l, r);
    if(seg[id] > th) return INF;
    if(r - l == 1) return l;
    int m = (l + r) / 2;
    push(2 * id + 1, l, m);
    push(2 * id + 2, m, r);
    if(seg[2 * id + 1] <= th) return query(2 * id + 1, l, m, th);
    return query(2 * id + 2, m, r, th);
}

int getVal(int id, int l, int r, int p) {
    push(id, l, r);
    if(l + 1 == r) {
       return seg[id]; 
    }
    int m = (l + r) / 2;
    if(p < m) return getVal(2 * id + 1, l, m, p);
    return getVal(2 * id + 2, m, r, p);
}

void disp() {
    for(int i = 0; i < N; i++) {
        int k = getVal(0, 0, N, i);
        cout << k;
        cout << " \n"[i == N - 1];
    }
}


inline int Abs(int x) {
return x < 0 ? -x : x;
}

inline void solve() {
    cin >> N >> K >> D;
    fill(seg, seg + maxN * 4, 2 * maxN);
    for(int i = 0; i < N; i++) cin >> x[i];
    if(!D) {
        int last = 0, bestL = 0, bestR = 0;
        for(int i = 0; i < N; i++) {
            if(i && x[i] != x[i - 1]) {
                last = i;
            }
            if((i - last > bestR - bestL) || ((i - last == bestR - bestL) && last < bestL)) {
                bestL = last;
                bestR = i;
            }
        }
        cout << bestL + 1 << " " << bestR + 1 << '\n';
        return;
    }
    unordered_map<int, int> lastidx = unordered_map<int, int>();
    lastidx.reserve(N);
    int bestL = 0, bestR = 0, lastMod = 0;
    for(int i = 0; i < N; i++) {
        if(i && (Abs(x[i] - x[i - 1]) % D)) {
            modify(0, 0, N, 0, i, INF);
            m1 = m2 = 0;
            lastMod = i;
        }
        /*
        if(lastidx.count(x[i]) && (lastMod < lastidx[x[i]] + 1)) {
            modify(0, 0, N, lastMod, lastidx[x[i]] + 1, INF);
            lastMod = lastidx[x[i]] + 1;
        }
        */
        if(lastidx.count(x[i])) {
            modify(0, 0, N, 0, lastidx[x[i]] + 1, INF);
        }
        lastidx[x[i]] = i;
        int last = i;
        while(m1 && x[maxes[m1 - 1]] <= x[i]) {
            m1--;
            int lef = m1 ? maxes[m1 - 1] + 1 : 0;
            modify(0, 0, N, lef, last, (x[i] - x[maxes[m1]]) / D);
            last = lef;
        }
        maxes[m1++] = i;
        last = i;
        while(m2 && x[mins[m2 - 1]] >= x[i]) {
            m2--;
            int lef = m2 ? mins[m2 - 1] + 1 : 0;
            modify(0, 0, N, lef, last, (x[mins[m2]] - x[i]) / D);
            last = lef;
        }
        mins[m2++] = i;
        int k = getVal(0, 0, N, i);
        modify(0, 0, N, i, i + 1, i - k); //set ith place to i
        int nextL = query(0, 0, N, i + K);
        //cout << "for i = " << i << ", l = " << nextL << endl;
        if((i - nextL > bestR - bestL) || (i - nextL == bestR - bestL && nextL < bestL)) {
            bestL = nextL;
            bestR = i;
        }
        //cout << "N = " << N << endl;
        //disp();
    }
    cout << bestL + 1 << " " <<  bestR + 1 << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T = 1;
    while(T--) {
        solve();
    }
}


