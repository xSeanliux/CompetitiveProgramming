#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> leaves, vals;

int N, yv, pv;

signed main(){
   cin >> N >> yv >> pv;
   vals.resize(N);
   for(int i = 0; i < N; i++) cin >> vals[i];
   sort(vals.begin(), vals.end());
   pq.push(yv);
   while(pq.size() < N){
        int t = pq.top();
        pq.pop();
        cout << "Popping " << t << " and pushing " << t + yv << " and " << t + pv << endl;
        pq.push(t + yv);
        pq.push(t + pv);
   }
   while(pq.size()){
        leaves.push_back(pq.top());
        pq.pop();
   }
   sort(leaves.begin(), leaves.end());
   reverse(leaves.begin(), leaves.end());

    for(int u : leaves){
        cout << u << " ";
    }
    cout << endl;
   int ans = 0;
   for(int i = 0; i < N; i++) ans += leaves[i] * vals[i];
   cout << ans << endl;
}
