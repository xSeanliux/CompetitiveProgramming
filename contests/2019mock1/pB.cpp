#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<vector<char> > res[8];

int n;

inline int pow(int a, int b){
    if(!a) return 0;
    if(!b) return 1;
    int res = pow(a, b/2);
    res = res * res;
    if(b % 2) res = res * a;
    return res;
}

void solve(int N){
    //cout << "Solving N = " << N << endl;
    if(!N) return;
    solve(N - 1);
    int len = pow(3, N);
    res[N].resize(len);
    //cout << "N = " << N - 1 << ": " << endl;
    for(int i = 0; i < len; i++) res[N][i].resize(len);
    for(int i = 0; i < len/3; i++){
        for(int j = 0; j < len/3; j++){
            res[N][i][j] =res[N - 1][i][j];
            res[N][i][j + len/3] =res[N - 1][i][j];
            res[N][i][j + 2 * len/3] =res[N - 1][i][j];
            res[N][i + len/3][j] =res[N - 1][i][j];
            res[N][i + len/3][j + 2 * len/3] =res[N - 1][i][j];
            res[N][i + 2 * len/3][j] =res[N - 1][i][j];
            res[N][i + 2 * len/3][j + len/3] = res[N - 1][i][j];
            res[N][i + 2 * len/3][j + 2 * len/3] = res[N - 1][i][j];
            res[N][i + len/3][j + len/3] = '#';
        }
    }
}

int main(){
    ericxiao;
    cin >> n;
    res[0] = { { '.' } };
    solve(n);
    int l = pow(3, n);
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            cout << res[n][i][j];
        }
        cout << '\n';
    }
}


