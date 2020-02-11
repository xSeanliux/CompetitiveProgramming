#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e4 + 10;

int pre[maxN], N, Q, x, y;

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        pre[x]++;
    }
    for(int i = 1; i <= maxN; i++) pre[i] += pre[i - 1];
    cin >> Q;
    int A, B, C;
    while(Q--){
        cin >> x;
        A = pre[x - 1];
        C = pre[maxN - 1] - pre[x];
        B = pre[x] - pre[x - 1];
        //cout << "A = " << A << ", B = " << B << ", C = " << C << endl;
        cout << A * (B + C) + B * (B - 1) / 2 + B * C << '\n';
    }
}
