#include <deque>
#include <iostream>
#include <utility>
using namespace std;

int n, k, dp[(int)1e6 + 10], x, sig = 0;
deque<pair<int, int> > deq;

int main(){
    cin >> n >> k;
    deq.push_back({0, 0}); //pos, sum
    for(int i = 1; i <= n; i++){
        cin >> x;
        sig += x;
        while(!deq.empty() && deq.front().first < max(0, i - k)) deq.pop_front();
        dp[i] = deq.front().second + sig;
        cout << "dp[" << i << "] = " << dp[i] << endl;
        while(!deq.empty() && deq.back().second <= dp[i] - sig) deq.pop_back();
        deq.push_back({i, dp[i] - sig});
    }
    cout << dp[n] << endl;
}
