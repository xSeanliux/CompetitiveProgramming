#include <iostream>
#define int long long int
using namespace std;

const int maxN = 5e5;
int N, pre[maxN + 10], dp1[maxN + 10], dp2[maxN + 10], dp3[maxN + 10], tgt;

signed main(){
    cin >> N;
    cin >> pre[0];
    for(int i = 1; i < N; i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    if(pre[N-1] % 3){
        cout << 0 << endl;
        return 0;
    }
    tgt = pre[N-1] / 3;
    dp1[0] = (pre[0] == tgt);
    for(int i = 1; i < N; i++){
        dp1[i] = dp1[i-1];
        if(pre[i] == tgt) dp1[i]++;
        //cout << "dp1[" << i << "] = " << dp1[i] << endl;
    }
    //cout << endl;
    dp2[0] = 0;
    for(int i = 1; i < N; i++){
        dp2[i] = dp2[i-1];
        if(pre[i] == 2 * tgt){
            dp2[i] += dp1[i-1];
        }
        //cout << "dp2[" << i << "] = " << dp2[i] << endl;
    }
    cout << dp2[N - 2] << endl;
}
