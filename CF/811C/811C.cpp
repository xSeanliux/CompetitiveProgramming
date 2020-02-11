#include <iostream>
#include <utility>
#include <map>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

map<int, pii> pos;
vector<int> vec;

int N;

int main() {
    ericxiao;
    cin >> N;
    vec.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        if(pos.count(vec[i])){
            pos[vec[i]].S = i;
        } else {
            pos.insert({vec[i], {i, i}});
        }
    }
    vector<int> last, dp;
    for(auto p : pos){
        last.push_back(p.S.S);
        //cout<< p.S.S << endl;
    }
    sort(last.begin(), last.end());
    dp.resize(last.size());
    bool has[6000];
    int ans = 0, l, r, cxor = 0, cmax = 0;
    for(int i = 0; i < last.size(); i++){
        l = pos[ vec[last[i]] ].F, r = last[i];
        //cout << "Looking at l = " << l << ", r = " << r << endl;
        cmax = cxor = 0;
        bool isgood = true;
        fill(has, has + 6000, false);
        for(int j = r; j >= l; j--){
            if(has[vec[j]]) continue;
            has[vec[j]] = true;
            l = min(l, pos[vec[j]].F);
            if(pos[vec[j]].S > r){
                dp[i] = -2147483647;
                isgood = false;
                break;
            }
            cxor ^= vec[j];
        }
        if(isgood){
            for(int j = 0; j < i && last[j] < l; j++){
                cmax = max(cmax, dp[j]);
            }
            dp[i] = cmax + cxor;
            ans = max(ans, dp[i]);
        }

    }
    cout << ans << endl;
}
