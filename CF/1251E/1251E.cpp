#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define F first
#define S second
#define int long long int
using namespace std;

int t, n, m, p, ans;
map<int, vector<int> > mp;
priority_queue<int, vector<int>, greater<int> > pq;
signed main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> n;
        mp = map<int, vector<int> >();
        mp[0] = vector<int>();
        pq = priority_queue<int, vector<int>, greater<int> >();
        for(int i = 0; i < n; i++){
            cin >> m >> p;
            mp[m].push_back(p);
        }
        int cnt = 0, _t;
        for(auto it = --mp.end(); it->F; it = --it){
            cout << "Current m: " << it->F << endl;
            for(int u : it->S){
                pq.push(u);
                cnt++;
            }
            for(int i = 0; i < it->F - (n - cnt); i++){
                _t = pq.top();
                pq.pop();
                ans += _t;
            }
            cout << "Ua: " << prev(it)->F << endl;
        }
        cout << ans << endl;
    }
}
