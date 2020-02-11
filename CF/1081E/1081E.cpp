#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> ans;
vector<pii> pairs;

int N;

signed main(){
    ericxiao;
    cin >> N;
    N /= 2;
    ans.resize(2 * N);
    pairs.resize(N + 1);
    for(int i = 1; i < 2 * N; i += 2) cin >> ans[i];
    pairs[0] = {0, 0};
    pii p;
    int d, od, a, b;
    for(int i = 1; i <= N; i++){
        p = {-1, (int)1e10};
        for(int k = 1; k * k <= ans[2 * i - 1]; k++){
            if(!(ans[2 * i - 1] % k)){
                //cout << "Found factor " << k << endl;
                d = k;
                od = ans[2 * i - 1] / d;
                if((od - d) % 2) continue;
                a = (od - d) / 2;
                b = (od + d) / 2;
                //cout << "Perhaps " << a << "^2 and " << b << "^2?" << endl;
                if(a > pairs[i - 1].S && b < p.S){
                    p = {a, b};
                }
            }
        }
        if(p.F == -1){
            cout << "No" << endl;
            return 0;
        } else {
            //cout << "Final pair: " << p.F << ", " << p.S << endl;
            pairs[i] = p;
            ans[2 * i - 2] = (pairs[i - 1].S + p.F) * (p.F - pairs[i - 1].S);
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < 2 * N; i++) cout << ans[i] << " \n"[i == 2*N - 1];
}
