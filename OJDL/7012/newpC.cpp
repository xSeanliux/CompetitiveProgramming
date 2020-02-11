#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 1e8;

int q, h, n;
vector<int> hei, dp;

int main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> h >> n;
        hei.resize(n);
        dp.resize(n);
        int od = 0, ed = 0;
        for(int i = 0; i < n; i++){
            cin >> hei[i];
            dp[i] = INF;
        }
        for(int i = 1; i < n; i++){
            if(hei[i - 1] - hei[i] == 1){
                if(i % 2) od++;
                else ed++;
            }
        }
        cout << min(od, ed) << endl;

    }
}
