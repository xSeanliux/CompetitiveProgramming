#include <iostream>
#include <vector>
#include <map>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;
//first 30 terms

const int maxN = 1e5 + 10;
bool can[maxN];
vector<int> arrs;
map<int, pii> mp;
int N;

signed main(){
     arrs.push_back(1);
     arrs.push_back(2);
     can[1] = true;
     mp[1] = {1, 2};
     for(int i = 2; i < 60; i++){
        if(i & 1){
            int mx = 0;
            for(int i = 1;; i++){
                if(!can[i]){
                    mx = i;
                    break;
                }
            }
            arrs.push_back(mx + arrs.back());
        } else {
            arrs.push_back(arrs.back() * 2);
        }
        for(int j = 0; j < i; j++){
            mp[arrs[i] - arrs[j]] = {j + 1, i + 1};
            if(arrs[i] - arrs[j] >= maxN) continue;
            can[arrs[i] - arrs[j]] = true;
        }
     }
     int n, x;
     cin >> n;
     vector<int> already;
     for(auto p : mp) already.push_back(p.F);
     while(n--){
        cin >> x;
        if(mp.count(x)){
            cout << mp[x].S << " " << mp[x].F << endl;
            continue;
        }
        int bef = lower_bound(already.begin(), already.end(), x) - already.begin(); //bef numbers that are already done befre it
        bef = x - bef;
        cout << 60 + 2 * bef << " " << 60 + 2 * bef - 1 << endl;
     }
}
