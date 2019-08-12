#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <deque>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pii pair<int,int>
using namespace std;

int T, N, l, r;
deque<pii> times;
vector<int> ans;
vector<vector<pii> > in;
int main(){
    cin >> T;
    while(T--){
        ans.clear();
        ans.resize(N + 1);
        in.clear();
        in.resize(5006);
        times = deque<pii>();
        cin >> N;
        for(int t = 1; t <= N; t++){
            cin >> l >> r;
            in[l].push_back({r, t}); //leave time / index
        }
        for(int t = 1; t <= 5000; t++){ //t'th second
            //cout << "TIME = " << t << endl;
            for(auto p : in[t]){
                times.push_back(p);
            }
            while(times.size() && times.front().first < t){
                //cout << "POPPING " << times.front().second << endl;
                ans[times.front().second] = 0;
                times.pop_front();
            }
            if(times.size()){
                //cout << "GIVING " << times.front().second << " TO TIME " << t << endl;
                ans[times.front().second] = t;

                times.pop_front();
            }

        }
        for(int i = 1; i <= N; i++) cout << ans[i] << " \n"[i == N];
    }
}
