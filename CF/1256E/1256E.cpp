#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 2e5 + 10;

int totsum = 0, diff[maxN], N, dp[maxN], from[maxN], team[maxN];
pii vals[maxN];
signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vals[i].F;
        totsum += vals[i].F;
        vals[i].S = i;
    }
    sort(vals, vals + N);
    for(int i = 0; i < N - 1; i++){
        diff[i] = vals[i + 1].F - vals[i].F;
        //cout << diff[i] << " ";
    }
    //cout << endl;
    int cm = 0, maxval = 0, transfrom = -1, maxAt = -1;
    for(int i = 2; i < N - 3; i++){
        dp[i] = cm + diff[i];
        from[i] = transfrom;
        if(i >= 4 && cm < dp[i - 2]){
            cm = dp[i - 2];
            transfrom = i - 2;
        }
        if(i < N - 3 && maxval < dp[i]){
            maxval = dp[i];
            maxAt = i;
        }
        //cout << "dp[" << i << "] = " << dp[i] << endl;
        //cout << "Coming from " << from[i] << endl;
    }
    //cout << "Maximum rightmost take: " << maxAt << endl;
    vector<int> transitions;
    int t = maxAt;
    while(t != -1){
        transitions.push_back(t);
        t = from[t];
    }
    reverse(transitions.begin(), transitions.end());
    transitions.push_back(N - 1);
    //for(int u : transitions) cout << u << " ";
    //cout << endl;
    int currentAt = 0, cnt = 0;
    for(int u : transitions){
        ++cnt;
        for(int i = currentAt; i <= u; i++) team[vals[i].S] = cnt;
        currentAt = u + 1;
    }
    cout << vals[N - 1].F - vals[0].F - maxval << " " << transitions.size() << '\n';
    for(int i = 0; i < N; i++) cout << team[i] << " \n"[i == N - 1];
}
