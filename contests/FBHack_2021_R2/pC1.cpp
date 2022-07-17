#include <iostream>
#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e6 + 326;

int T, N, M, K, pre[maxN];
vector<char> mp[maxN];
string s;

int Abs(int x){
    return x < 0 ? -x : x;
}

inline void solve(int tc){
    cin >> N >> M >> K;
    K--;
    int ans;
    for(int i = 0; i < N; i++){
        mp[i] = vector<char>();
        mp[i].resize(M);
        for(int j = 0; j < M; j++) cin >> mp[i][j];
    }
    //solve if going up
    fill(pre, pre + N, 0);
    for(int j = 0; j < M; j++){
        int cnt = 0;
        for(int i = 0; i < N; i++){
           if(mp[i][j] == 'X'){
               cnt++;
           } else continue;
           //do things
           if(i >= K) pre[i - K]++;
           //
           if(cnt == K + 1) break;
           if(i >= K) pre[i - K + 1]--;
        }
    }
    ans = pre[0];
    for(int i = 1; i < N; i++){
        pre[i] += pre[i - 1];
        ans = min(ans, pre[i] + i);
    }
    //falling down
    fill(pre, pre + N, 0);
    for(int j = 0; j < M; j++){
        int cnt = 0;;
        for(int i = N - 1; i >= 0; i--){
           if(mp[i][j] == 'X'){
               cnt++;
           } else continue;
           if(K >= i) pre[K - i]++;
           if(cnt == N - K) break;
           if(K >= i) pre[K - i + 1]--;
        }
    }
    ans = min(ans, pre[0]);
    for(int i = 1; i < N; i++){
        pre[i] += pre[i - 1];
        ans = min(ans, pre[i] + i);
    }
    cout << "Case #" << tc << ": " << ans << endl;
}

signed main(){
    ericxiao;
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }

}


