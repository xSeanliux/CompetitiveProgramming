#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

inline void dandiaohua(vector<pii> &v){
    sort(v.begin(), v.end(), [](pii a, pii b){
        return (a.F == b.F) ? a.S > b.S : a.F < b.F;
    });
    static vector<pii> tmp;
    static int _id;
    for(int i = 0; i < v.size(); i++){
        _id = i;
        if(!tmp.size() || *tmp.rbegin()->S < v[i].S) tmp.push_back(v[i]);
        while(i < v.size() && v[i].F == v[_id].F) i++;
        i--;
    }
    swap(tmp, v);
}

int N, K, cmax = 0, t;
vector<pii> dp[205][205], vals; //i is last, j numbers, last number is k
signed main(){
    cin >> N >> K;
    if(N == K){
        int ans = 0;
        for(int i = 0; i < N; i++){
            cin >> t;
            if(t < cmax){
                ans += cmax - t;
            }
            cmax = max(cmax, t);
        }
        cout << ans << endl;
        return 0;
    }
    vals.resize(N)
    for(int i = 0; i < N; i++){
        cin >> vals[i];
        dp[i][1].push_back({vals[i], 0});
    }
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < j; k++){

            }
        }
    }

}
