#include <iostream>
#include <vector>
#include <string.h>
#define vv vector<vector<int> >
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int MOD = 1e9 + 7, maxN = 1e5 + 25;

int N, Q, com, l, r, a, b;
string s;
vv seg[maxN << 2];
int rev[maxN << 2];

inline int add(int a, int b){
    return (a + b < MOD ? a + b : a + b - MOD);
}


inline int sub(int a, int b){
    return (a - b < 0 ? a - b : a - b + MOD);
}

inline int mult(int a, int b){
    return a * b % MOD;
}

vv operator*(vector<vector<int> > &a, vector<vector<int> > &b) {
    vector<vector<int> > res;
    /*
    cout << "a = " << endl;
    for(vector<int> v : a){
        for(int u : v){
            cout << u << " ";
        }
        cout << endl;
    }
    cout << "b = " << endl;
    for(vector<int> v : b){
        for(int u : v){
            cout << u << " ";
        }
        cout << endl;
    }
    */
    res.resize(a.size());
    for(int i = 0; i < a.size(); i++){
        res[i].resize(b[0].size());
        for(int j = 0; j < b[0].size(); j++){
            //cout << "Calculating res[" << i << "][" << j << "]" << endl;
            res[i][j] = 0;
            for(int k = 0; k < a[0].size(); k++){
                //cout << "Adding" << "a[" << i << "][" << k << "] * b[" << k << "][" << j << "] = " << a[i][k] * b[k][j] << endl;
                res[i][j] = add(res[i][j], mult(a[i][k], b[k][j]));
                //cout << "res[" << i << "][" << j << "] = " << res[i][j];
            }
        }
    }
    return res;
}

void push(int id, int l, int r){
    if(rev[id] % 2){
        swap(seg[id][0][0], seg[id][1][1]);
        swap(seg[id][0][1], seg[id][1][0]);
    }
    if(l + 1 < r){
        rev[2 * id + 1] += rev[id];
        rev[2 * id + 2] += rev[id];
    }
    rev[id] = 0;


}

inline void pull(int id){
    seg[id] =  seg[2 * id + 2] * seg[2 * id + 1];
}

void build(int id, int l = 0, int r = N){
    rev[id] = 0;
    if(l + 1 == r){
        seg[id] = {{1, 0}, {0, 1}};
        if(s[l] == 'A') seg[id][0][1] = 1;
        else seg[id][1][0] = 1;
        return;
    }
    int m = (l + r) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m, r);
    pull(id);
    /*
    cout << "Seg[" << l << ", " << r << "] = " << endl;
    for(vector<int> v : seg[id]){
        for(int u : v) cout << u << " ";
        cout << endl;
    }
    */
}

void modify(int id, int ql, int qr, int l = 0, int r = N){
    push(id, l, r);
    if(r <= ql || l >= qr) return;
    if(ql <= l && r <= qr){
        rev[id] += 1;
        push(id, l, r);
        return;
    }
    int m = (l + r) / 2;
    modify(2 * id + 1, ql, qr, l, m);
    modify(2 * id + 2, ql, qr, m, r);
    pull(id);
}

vv query(int id, int ql, int qr, int l = 0, int r = N){
    push(id, l, r);
    //cout << "Push" << endl;
    if(r <= ql || l >= qr) return {{1, 0}, {0, 1}};
    if(ql <= l && r <= qr) return seg[id];
    int m = (l + r) / 2;
    vv lft = query(2 * id + 1, ql, qr, l, m);
    vv rgt = query(2 * id + 2, ql, qr, m, r);
    //cout << "Finished query" << endl;
    return rgt * lft;
}



signed main(){
    ericxiao;
    cin >> N >> Q >> s;
    build(0);
    vv res, m;
    while(Q--){
        cin >> com;
        if(com == 1){
            cin >> l >> r;
            modify(0, l - 1, r);
        } else if(com == 2){
            cin >> l >> r >> a >> b;
            vv res = query(0, l - 1, r);
            m = {{a}, {b}};
            res = res * m;
            cout << res[0][0] << " " << res[1][0] << endl;
        }
    }
}

