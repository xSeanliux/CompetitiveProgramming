#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, ta, tb, k;
vector<int> a, b;


int main(){
    cin >> n >> m >> ta >> tb >> k;
    a.resize(n); b.resize(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    if(k >= min(n, m)){
        cout << -1 << endl;
        return 0;
    }
    int ans = -1;
    for(int i = -1; i < k; i++){ //fucking hell, this has to start from -1
        int takeTime = a[i + 1]; //
        int nextBusInd = lower_bound(b.begin(), b.end(), takeTime + ta) - b.begin() + (k - i - 1);
        if(nextBusInd < m){
            ans = max(ans, b[nextBusInd] + tb);
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
