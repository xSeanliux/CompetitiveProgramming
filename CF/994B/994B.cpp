#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

int sum = 0, n, k, t;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> ans, coin;
vector<pii> pows;

inline void add(int x){
    sum += x;
    pq.push(x);
    if(pq.size() > k){
        sum -= pq.top();
        pq.pop();
    }
}

signed main(){
    cin >> n >> k;
    pows.resize(n);
    coin.resize(n);
    ans.resize(n);
    for(int i = 0; i < n; i++){
        cin >> pows[i].F;
        pows[i].S = i;
    }
    for(int i = 0; i < n; i++) cin >> coin[i];
    sort(pows.begin(), pows.end());
    for(int i = 0; i < n; i++){
        ans[pows[i].S] = sum + coin[pows[i].S];
        //cout << "ans[" << pows[i].S << "] has " << sum << endl;
        add(coin[pows[i].S]);
    }
    for(int x : ans) cout << x << " ";
}
