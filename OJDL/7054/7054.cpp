#include <iostream>
#include <vector>
#define vv vector<vector<int>>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int MOD = 20191126;

vv I, V, A;

inline int add(int a, int b){
    return (a + b > MOD) ? a + b - MOD : a + b;
}

inline int sub(int a, int b){
    return (a - b < 0 ? a - b + MOD : a - b);
}


void show(vv v){
    for(vector<int> u : v){
        for(int x : u) cout << x << " ";
        cout << endl;
    }
}

vv mult(vv a, vv b){
    vv c;
    c.resize(a.size());
    for(int i = 0; i < a.size(); i++){
        c[i].resize(b[0].size());
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < a[0].size(); k++){
                c[i][j] = add(c[i][j], a[i][k] * b[k][j] % MOD);
            }
        }
    }
    return c;
}

vv exp(vv b, int e){
    if(!e) return I;
    vv res = exp(b, e/2);
    res = mult(res, res);
    if(e % 2) res = mult(res, b);
    return res;
}

int Q, n, k;

signed main(){
    I.resize(6);
    for(int i = 0; i < 6; i++){
        I[i].resize(6);
        for(int j = 0; j < 6; j++) I[i][j] = (i == j);
    }
    V = {
        {
            0, 1, 0, 0, 0, 0
        },
        {
            1, 1, 0, 0, 0, 0
        },
        {
            1, 1, 1, 0, 0, 0
        },
        {
            1, 1, 1, 1, 0, 0
        },
        {
            1, 1, 1, 1, 1, 0
        },
        {
            1, 1, 1, 1, 1, 1
        }
    };
    A ={
        {
            0
        },
        {
            1
        },
        {
            1
        },
        {
            1
        },
        {
            1
        },
        {
            1
        }
    };
    vv _V, res;
    cin >> Q;
    while(Q--){
        cin >> k >> n;
        _V = V;
        _V = exp(_V, n - 1);
        //show(_V);
        res = mult(_V, A);
        cout << res[k + 1][0] << endl;
    }
}
