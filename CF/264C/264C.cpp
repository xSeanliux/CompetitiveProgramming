#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);
#define int long long int
using namespace std;

const int maxN = 1e5 + 10, INF = 1e17;

vector<int> colour, val;
int q, a, b, n, maxSame[maxN], aS, aNS, res, ans;
pii notSame[3];

inline void bs(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            if(notSame[j] < notSame[j + 1]) swap(notSame[j], notSame[j + 1]);
        }
    }
    if(notSame[0].S == notSame[1].S){
        swap(notSame[1], notSame[2]);
    }
}

signed main(){
    ericxiao;
    cin >> n >> q;
    colour.resize(n);
    val.resize(n);
    for(int i = 0; i < n; i++) cin >> val[i];
    for(int i = 0; i < n; i++) cin >> colour[i];
    while(q--){
        cin >> a >> b;
        ans = 0;
        for(int i = 0; i < 3; i++) notSame[i] = {0, -i};
        fill(maxSame, maxSame + n + 5, -INF);
        for(int i = 0; i < n; i++){
            aS = -INF;
            if(maxSame[colour[i]] != -INF){
                aS = maxSame[colour[i]] + val[i] * a;
            }
            if(notSame[0].S != colour[i]){
                aNS = notSame[0].F + val[i] * b;
            } else {
                aNS = notSame[1].F + val[i] * b;
            }
            res = max(aS, aNS);
            ans = max(ans, res);
            maxSame[colour[i]] = max(maxSame[colour[i]], res);
            notSame[2] = {res, colour[i]};
            bs();
        }
        cout << ans << '\n';
    }
}
