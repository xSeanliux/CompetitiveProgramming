#include <iostream>
#include <utility>
#include <vector>
#include <deque>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 1e6;

deque<pii> dq;
vector<int> vec, ans;

int n;

int main(){
    ericxiao;
    cin >> n;
    ans.resize(n);
    vec.resize(2 * n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    dq.clear();
    pii p, pp;
    int k, mind = INF;
    for(int r = 2; r >= 0; r--){
        for(int i = n - 1; i >= 0; i--){
            p = {vec[i], i + r * n};
            //cout << "Looking at " << vec[i] << endl;
            //cout << "Current Queue: " << endl;
            //for(auto p : dq){
            //    cout << "(" << p.F << ", " << p.S << ") ";
            //}
            //cout << endl;
            if(dq.size() && dq.front().F >= p.F){
                if(ans[dq.front().S % n] != INF)
                    ans[i] = 1 + ans[dq.front().S % n];
                else ans[i] = INF;
            } else {
                if(dq.size()){
                    k = vec[i] / 2;
                    //cout << "k = " << k << endl;
                    if(vec[i] % 2 == 0) k--;
                    pp = {k, INF};
                    //cout << "Searching " << pp.F << ", -1" << endl;
                    auto res = lower_bound(dq.begin(), dq.end(), pp, greater<pii>() );
                    if(res != dq.end()){
                        ans[i] = res->S - i - r * n;
                        mind = min(mind, res->S);
                        //cout << "Found " << res->F << ", " << res->S << endl;
                    }
                    else ans[i] = INF;
                } else
                    ans[i] = INF;
            }
            if(mind != INF)
                ans[i] = min(ans[i], mind - i);
            while(dq.size() && dq.front().F >= p.F) dq.pop_front();
            dq.push_front(p);
            //cout << "mind = " << mind << endl;
            //cout << "ans[" << i << "] = " << ans[i] << endl;
        }
    }
    for(int i : ans){
        cout << ((i == INF) ? -1 : i) << " ";
    }
    cout << endl;
}
