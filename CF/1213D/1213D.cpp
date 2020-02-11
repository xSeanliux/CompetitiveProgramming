#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 250000;

vector<priority_queue<int> > vec;
vector<pii> ans;
int n, v, k;

int main(){
    cin >> n >> k;
    vec.resize(maxN);
    ans.resize(maxN);
    for(int i = 0; i < maxN; i++){
        ans[i] = {0, 0};
    }
    int res = maxN * 20;
    for(int i = 0; i < n; i++){
        cin >> v;
        int t = 0;
        while(v >= 0){
            vec[v].push(t);
            //cout << "vec[" << v << "] push " << t << endl;
            ans[v].F++;
            ans[v].S += t;
            if(ans[v].F > k){
                ans[v].F--;
                ans[v].S -= vec[v].top();
                vec[v].pop();
            }
            if(ans[v].F == k){
                //cout << "Vec[" << v << "].size() == " << k << endl;
                res = min(res, ans[v].S);
            }
            if(!v) break;
            v /= 2;
            t++;
        }
    }
    cout << res << endl;
}
