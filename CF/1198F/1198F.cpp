#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

int n, allgcd;
vector<pii> vec;
vector<int> ans;

int main(){
    ericxiao;
    cin >> n;
    vec.resize(n);
    ans.resize(n);
    int g;
    for(int i = 0; i < n; i++){
        cin >> vec[i].F;
        vec[i].S = i;
        g = (i ? gcd(g, vec[i].F) : vec[i].F);
    }
    time_t stt = clock(), endd;
    if(g > 1){
        cout << "NO" << endl;
        return 0;
    }
    pii p;
    do{
        random_shuffle(vec.begin(), vec.end());
        p.F = vec[0].F;
        p.S = vec[1].F;
        ans[vec[0].S] = 0;
        ans[vec[1].S] = 1;
        for(int i = 2; i < n; i++){
            if(gcd(p.F, vec[i].F) < p.F){
                p.F = gcd(p.F, vec[i].F);
                ans[vec[i].S] = 0;
            } else {
                p.S = gcd(p.S, vec[i].F);
                ans[vec[i].S] = 1;
            }
        }
        if(p.F == 1 && p.S == 1){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                cout << ans[i] + 1 << " \n"[i == n - 1];
            }
            return 0;
        }
    } while((double)clock() - stt <= 0.1 * CLOCKS_PER_SEC);
    cout << "NO" << endl;
}
