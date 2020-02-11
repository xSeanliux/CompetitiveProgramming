#include <iostream>
#define int unsigned long long int
using namespace std;

const int MOD = 1e9 + 7;
int l, r;

signed main(){
    cin >> l >> r;
    int oddcnt = 1, evencnt = 2, lE, rE, ll, rr;
    int currentInd = 0, ans = 0;
    bool current = 0;
    for(int i = 0; i < 62; i++){
        lE = (1ULL << i);
        rE = (1ULL << (i + 1)) - 1;
        if(rE < l || lE > r){
            if(i % 2) evencnt += 2 * (rE - lE + 1);
            else oddcnt += 2 * (rE - lE + 1);
            continue;
        }
        ll = max(lE, l);
        rr = min(rE, r);
        //cout << "ll = " << ll << ", rr = " << rr << endl;
        //cout << "lE = " << lE << ", rE = " << rE << endl;
        if(i % 2){ //EVEN
            //cout << "evencnt  = " << evencnt << endl;
            ans += (((ll - lE) + (rr - lE) + evencnt) % MOD) * ((rr - ll + 1) % MOD) % MOD;
            //cout << "PLUS: " << (((ll - lE) + (rr - lE) + evencnt) % MOD) * (rr - ll + 1) % MOD << endl;
            evencnt += 2 * (rE - lE + 1);
        } else { //ODD
            //cout << "oddcnt  = " << oddcnt << endl;
            ans += (((ll - lE) + (rr - lE) + oddcnt) % MOD) * ((rr - ll + 1) % MOD) % MOD;
            //cout << "PLUS: " << (((ll - lE) + (rr - lE) + oddcnt) % MOD) * (rr - ll + 1) % MOD << endl;
            oddcnt += 2 * (rE - lE + 1);
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
