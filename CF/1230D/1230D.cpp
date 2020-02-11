#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

int n, ans = 0;

vector<int> a, b, oa, reps;

signed main(){
    cin >> n;
    a.resize(n);
    b.resize(n);
    oa.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        oa[i] = a[i];
    }
    sort(oa.begin(), oa.end());
    for(int i = 0; i < n - 1; i++){
        if(oa[i] == oa[i + 1] && (reps.empty() || *reps.rbegin() != oa[i])) reps.push_back(oa[i]);
    }
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++){
        for(int u : reps){
            if((a[i] & u) == a[i]){
                ans += b[i];
                break;
            }
        }
    }
    cout << ans << endl;
}
