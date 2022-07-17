#include <iostream>
#include <utility>
#define int long long int
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 5e5 + 326, maxL = 20;
int A[maxN], C[maxN], Q, anc[maxL][maxN], t, a, p, c, v, w;
bool isEmpty[maxN];

inline void initAnc(int p, int u){
    anc[0][u] = p;
    for(int i = 1; i < maxL; i++) anc[i][u] = anc[i - 1][anc[i - 1][u]];
}

inline int getNext(int v){
    for(int i = maxL - 1; i >= 0; i--){
        if(!isEmpty[anc[i][v]]){
            v = anc[i][v];
        }
    }
    return v;
}

inline pii buy(int v, int w){
   int bought = 0, spent = 0, amt;
   while(true){
       int n = getNext(v);
       if(isEmpty[n]) break;
       amt = min(A[n], w);
       A[n] -= amt;
       bought += amt;
       w -= amt;
       spent += amt * C[n];
       if(!A[n]) isEmpty[n] = true;
       if(!w) break;
   }
   return pii(bought, spent);
}

signed main(){
    ericxiao
    cin >> Q >> A[0] >> C[0];
    initAnc(0, 0);
    for(int i = 1; i <= Q; i++){
        cin >> t;
        if(t == 1){
            cin >> p >> a >> c;
            A[i] = a;
            C[i] = c;
            initAnc(p, i);
        } else {
            cin >> v >> w;
            pii res = buy(v, w);
            cout << res.F << " " << res.S << endl;
        }
    }
}
