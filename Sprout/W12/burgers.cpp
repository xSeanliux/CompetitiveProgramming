#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#define S second
#define F first
#define pii pair<int,int>
using namespace std;

int N, K, C, T, currentV, l = 0, r = 1;
vector<int> dp;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K >> C;
        dp.clear();
        dp.resize(N + 1);
        int ans = 0;
        deque<pii > q;
        for(int i = 1; i <= N; i++){
            cin >> currentV;
            while(q.size() && i - q.front().S > K){
                q.pop_front();
            }
            if(q.size()){
                dp[i] = max(q.front().F - C * i + currentV, currentV);
            } else {
                dp[i] = currentV; //nothing taken
            }
            ans = max(dp[i], ans);
            while(q.size() && q.back().F <= dp[i] + C * i) q.pop_back();
            q.push_back({dp[i] + C * i, i});
        }
        cout << ans << endl;
    }

}
