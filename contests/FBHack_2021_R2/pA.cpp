#include <iostream>
#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 326;

int T, N, M, outfit[maxN];
map<int, int> amnt;
queue<int> unmatched;
bool hasChanged[maxN], hasMatched[maxN];

inline void solve(int tc){
    cin >> N >> M;
    fill(hasChanged, hasChanged + M, false);
    for(int i = 0; i < M; i++){
        cin >> outfit[i];
    }
    int x, ans = 0;
    for(int i = 0; i < N; i++){
        amnt = map<int, int>();
        fill(hasMatched, hasMatched + M, false);
        for(int j = 0; j < M; j++){
            cin >> x;
            if(!amnt.count(x)) amnt[x] = 0;
            amnt[x]++;
        }
        for(int j = 0; j < M; j++){
            if(hasChanged[j]){
                if(amnt[outfit[j]]){
                    amnt[outfit[j]]--;
                    hasMatched[j] = true;
                }
            }
        }
        for(int j = 0; j < M; j++){
            if(!hasChanged[j]){
                if(amnt[outfit[j]]){
                    amnt[outfit[j]]--;
                    hasMatched[j] = true;
                }
            }
        }
        queue<int> remaining = queue<int>();
        for(auto [x, k] : amnt){
            for(int j = 0; j < k; j++) remaining.push(x);
        }
        for(int j = 0; j < M; j++){
            if(!hasMatched[j]){
              outfit[j] =  remaining.front();
              ans++;
              hasChanged[j] = true;
              remaining.pop();
            }
        }
    }
    //cout << "ans = " << ans << endl;
    for(int i = 0; i < M; i++){
        //cout << "hc[" << i << "] = " << hasChanged[i] << endl;
        if(hasChanged[i]) ans--;
    }
    cout << "Case #" << tc << ": " << ans << endl;
}

signed main(){
    ericxiao
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
}
