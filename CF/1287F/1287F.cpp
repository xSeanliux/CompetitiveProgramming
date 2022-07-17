#include <iostream>
#include <vector>
#include <utility>
#define vii vector<vector<int>>
#define int long long int
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 326, M = 998244353;
int x[maxN], v[maxN], p[maxN], np[maxN], N;
vii seg[maxN << 2];

inline int modexp(int b, int e) {
    int r = 1;
    while(e) {
        if(e & 1) r = r * b % M;
        b = b * b % M;
        e >>= 1;
    }
    return r;
}

inline int add(int a, int b) {
    return (a + b >= M ? a + b - M : a + b);
}

inline int inv(int x) {
    return modexp(x, M - 2);
}

inline int Abs(int x) {
    return x < 0 ? -x : x;
}

vvi update(vvi &a, vvi &b, int pr, int npr) {
    vvi ses = {
        {0, 0},
        {0, 0}
    };
    int a = 2 * id + 1, b = 2 * id + 2;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ses[id][i][j] = ((a[i][0] * b[0][j] % M) * inv(pr) % M + ((a[i][1] * b[1][j]) % M) * inv(npr) % M) % M;
        }
    }
    return ses;
}

inline void pull(int id, int m) {
    seg[id] = update(seg[2 * id + 1], seg[2 * id + 2], p[m], np[m]);
}

void build(int id = 0, int l = 0, int r = N - 1) {
    cout << "building " << id << ", " << l << ", " << r << endl;
    seg[id].resize(2);
    for(int i = 0; i < 2; i++) seg[id][i].resize(2);
    if(l + 1 == r) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                seg[id][i][j] = 1;
                seg[id][i][j] = i ? np[l] : p[l];
                seg[id][i][j] = seg[id][i][j] * (j ? np[r] : p[r]) % M;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    pull(id, m);
}

void modify(int id, int l, int r, int p, int i, int j, int v) {
    if(l + 1 == r) {
        seg[id][i][j] = v;
        return;
    }
    int m = (l + r) / 2;
    if(p < m) modify(2 * id + 1, l, m, p, i, j, v);
    else modify(2 * id + 2, m, r, p, i, j, v);
    pull(id, m);
}

vvi query(int id, int l, int r, int ql, int qr) {

}

int getSum() {
   int r = 0; 
   for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) r = add(r, seg[0][i][j]);
   return r;
}

signed main() {
   cin >> N; 
   for(int i = 0; i < N; i++){
       cin >> x[i] >> v[i] >> p[i];
       np[i] = (100 - p[i]) * inv(100) % M;
       p[i] = p[i] * inv(100) % M;
       cout << "pi = " << p[i] << ", npi = " << np[i] << endl;
   }
   build();
   vector<pii> ord = vector<pii>();
   for(int i = 0; i < N - 1; i++) {
       ord.emplace_back(i, 0);
       ord.emplace_back(i, 1);
       ord.emplace_back(i, 2);
       ord.emplace_back(i, 3);
   }
   sort(ord.begin(), ord.end(), [](pii a, pii b) {
    int v1 = (a.S & 1) ? v[a.F] : -v[a.F];
    int v2 = (b.S & 1) ? v[b.F] : -v[b.F];
    v1 += (a.S & 2) ? -v[a.F + 1] : v[a.F + 1];
    v2 += (b.S & 2) ? -v[b.F + 1] : v[b.F + 1];
    if(v1 < 0) return false;
    if(v2 < 0) return true;
    int d1 = x[a.F + 1] - x[a.F];
    int d2 = x[b.F + 1] - x[b.F];
    return d1 * v2 < d2 * v1;
   });
   int ans = 0;
   for(auto [idx, toBan] : ord) {
       //update ans += duration of this * possibilities / 2^N
       //ban();
       int dirL = (toBan & 1);
       int dirR = (toBan & 2) >> 1;
       int vel = (dirL ? 1 : -1) * v[idx] + (dirR ? -1 : 1) * v[idx + 1];
       cout << "vel = " << vel << endl;
       if(vel < 0) break;
       ans = add(ans, ((x[idx + 1] - x[idx]) * inv(vel) % M) * getSum() % M);
       modify(0, 0, N - 1, idx, dirL, dirR, 0);
   }
   cout << ans << endl;
}
