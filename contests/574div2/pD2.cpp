#include <iostream>
#include <string.h>
#include <vector>
#define int long long int
using namespace std;

int N, lens[20];
vector<string> v;

const int MOD = 998244353;

int Pow(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = Pow(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

int f(string s){
    //cout << "Running f(" << s << ")" << endl;
    int ret = 0;
    for(int l = 1; l <= 10; l++){
        int res = 0, k = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            res += Pow(10, k) * (s[i] - '0');
            k++;
            if(s.length() - i <= l){
                k++;
            }
        }
        //cout << "FOR" << res << ", appear" << lens[l] << "times" << endl;
        res = res * lens[l] % MOD;
        ret = (ret + res) % MOD;
    }
    for(int l = 1; l <= 10; l++){
        int res = 0, k = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.length() - i <= l){
                k++;
            }
            res += Pow(10, k) * (s[i] - '0');
            k++;

        }
        //cout << "FOR" << res << ", appear" << lens[l] << "times" << endl;
        res = res * lens[l] % MOD;
        ret = (ret + res) % MOD;
    }
    return ret;
}


signed main(){
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i];
        lens[v[i].length()]++;
    }
    int ans = 0;
    for(string s : v){
        ans = (ans + f(s)) % MOD;
    }
    cout << ans << endl;
}
