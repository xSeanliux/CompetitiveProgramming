#include <iostream>
#include <map>
#include <deque>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;


int n, k, t;
map<int, int> mp;
deque<pii> dq;

signed main(){
    ericxiao;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> t;
        mp[t]++;
    }
    for(auto p : mp) dq.push_back(p);
    int moves, c;
    pii l, r;
    while(k && dq.size() > 1){
        l = dq.front(), r = dq.back();
        if(k < min(l.S, r.S)) break;
        if(l.S <= r.S){
            dq.pop_front();
            c = min(k / l.S, dq.front().F - l.F);
            k -= c * l.S;
            if(c == dq.front().F - l.F) dq.front().S += l.S;
            else {
                l.F += c;
                dq.push_front(l);
            }
        } else {
            //cout << "Moving " << r.F << ", " << r.S << endl;
            dq.pop_back();
            c = min(k / r.S, r.F - dq.back().F);
            k -= c * r.S;
            if(c == r.F - dq.back().F) dq.back().S += r.S;
            else {
                r.F -= c;
                dq.push_back(r);
            }
        }
        //cout << "k = " << k << endl;
    }
    cout << dq.back().F - dq.front().F << endl;
}
