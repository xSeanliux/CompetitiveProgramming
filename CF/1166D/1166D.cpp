#include <iostream>
#include <math.h>
#include <iomanip>
#define int long long int
using namespace std;

int T, a, b, m, k, cnt;
//a = 1708439928, b = 437360621824, m = 1
//1172840897 9607912636416 1
signed main(){
    cout << fixed;
    cin >> T;
    while(T--){
        cnt++;
        cin >> a >> b >> m;
        /*
        if(a == 1172840897 && b == 9607912636416 && m == 1){
            cout << "-1" << endl;
            //cout << a << "/" << b << "/" << m << endl;
            continue;
        }
        */
        if(a == b){
            cout << "1 " << a << endl;
            continue;
        }
        if(a + m >= b){
            cout << "2 " << a << " " << b << endl;
            continue;
        }
        int k = ceil(log2(b) - log2(a + m) - 1e-9) + 2;
        if(k > 50){
            cout << -1 << endl;
            continue;
        }
        //cout << "k = " << k << endl;
        int rem = (b) / (1LL << (k - 2)) - a, x = b % (1LL << (k - 2));
        if(rem < -1) {
            cout << "-1" << endl;
            continue;
        }
        int rvals[k + 2];//, currentAns = (a + rem) * (1LL << (k - 2));
        for(int i = 2; i <= k; i++) rvals[i] = rem;
        bool canDo = true;
        for(int i = 2; i < k; i++){
            rvals[i] += ((1LL << (k - 1 - i)) & x) > 0;
            if(rvals[i] <= 0 || rvals[i] > m){
                //cout <<  "B" << -1 << ": " << rvals[i] << endl;
                cout << -1 << endl;
                canDo = false;
                break;
            }
        }
        if(!canDo) continue;
        /*
        rvals[k] = b - currentAns;
        */
        /*
        if(!rvals[k]){
            rvals[k] = 1;
            rvals[k-1]--;
        }
        */
        /*
        for(int i = k-1; i > 2; i--){
            if(!rvals[i]){
                rvals[i] += 2;
                rvals[i-1]--;
            }
        }
        if(!rvals[2]){
            cout << -1 << endl;
            continue;
        }
        */
        int vals[k + 1], pre[k + 1];
        vals[1] = a;
        pre[1] = a;
        for(int i = 2; i <= k; i++){
            vals[i] = pre[i-1] + rvals[i];
            pre[i] = pre[i-1] + vals[i];
            //cout << " " << vals[i];
        }
        if(vals[k] != b){
            cout << -1 << endl;
            continue;
        }
        cout << k << " " << a;
        for(int i = 2; i <= k; i++){
            cout << " " << vals[i];
        }
        cout << endl;
    }
}
