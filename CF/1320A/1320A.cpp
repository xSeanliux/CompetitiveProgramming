#include <iostream>
#include <map>
#define int long long int
using namespace std;

const int maxC = 1e6, maxN = 2e5 + 10;

int N, maxAns, x;
map<int,int> dp;
signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        dp[x - i] += x;
        maxAns = max(maxAns, dp[x - i]);
    }
    cout << maxAns << endl;
}
