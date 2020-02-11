#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

int T, n, s, ans, todel, tk;

vector<int> times;

signed main(){
    cin >> T;
    while(T--){
        cin >> n >> s;
        times.resize(n + 1);
        ans = 0;
        cin >> times[1];
        for(int i = 2; i <= n; i++){
            cin >> times[i];
            times[i] += times[i - 1];
            //cout << "times[" << i << "] = " << times[i] << endl;
        }

        if(times[n] <= s){
            cout << 0 << endl;
            continue;
        }
        for(int i = 1; i <= n; i++){
            if(times[i - 1] > s) continue;
            //cout << "NV: " << times[i] - times[i - 1] + s << endl;
            tk = upper_bound(times.begin(), times.end(), times[i] - times[i - 1] + s) - times.begin();
            //cout << "For i = " << i << ", can take " << tk << endl;
            if(tk >= ans){
                ans = tk;
                todel = i;
            }
        }
        cout << todel << endl;
    }
}
