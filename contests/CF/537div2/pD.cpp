#pragma GCC optimize ("O3")
#include <iostream>
#include <map>
#include <string.h>
using namespace std;

string s;
int N, a, b;
map<char, int> freqs;
const long long int MOD = 1e9 + 7;
void extgcd(long long int a, long long int b, long long int &x, long long int &y, long long int &d){
    if(!b){
        d = a;
        x = 1;
        y = 0;
    } else {
        extgcd(b, a % b, y, x, d);
        y -= a/b * x;
    }
}

int getNum(char c){
    if(c >= 'A' && c <= 'Z') return (c - 'A' + 26);
    else return c - 'a';
}

char getAlph(int n){
    if(n > 25) return (n - 26 + 'A');
    else return n + 'a';
}

long long int inv(long long int a, long long int m){
    long long int x, y, g;
    extgcd(a, m, x, y, g);
    while(x < 0) x += m;
    return x % m;
}

long long int fact(long long int n, long long int m){
    long long int res = 1;
    for(int i = 1; i <= n; i++){
        res = (res * i) % m;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> N;
    int ways[s.length() + 1];
    for(int i = 0; i < s.length(); i++){
        if(freqs.count(s[i])) freqs[s[i]]++;
        else freqs.insert({s[i], 1});
    }
    for(int i = 0; i <= s.length(); i++) ways[i] = 0;
    ways[0] = 1;
    for(auto p : freqs){
        for(int i = s.length(); i >= p.second; i--){
            ways[i] = (ways[i] + ways[i - p.second]) % MOD;
            //printf("ways[%d] += ways[%d] = %d\n", i, i - p.second, ways[i - p.second]);
        }
    }
    long long int n_2_fact = fact(s.length()/2, MOD), denom = 1;
    for(auto k : freqs){
        denom = (denom * fact(k.second, MOD)) % MOD;
    }
    //cout << "denom = " << denom << endl;
    long long int W;
    if(denom > n_2_fact * n_2_fact) W = 0;
    else {
        denom = inv(denom, MOD);
        W = (n_2_fact * n_2_fact) % MOD * denom % MOD;
        //printf("n2! = %lld, denom = %lld, W = %lld\n", n_2_fact, denom, W);
    }
    //cout << "dp[" << s.length()/2 << "] = " << ways[s.length()/2] << endl;
    //for(int i = 0; i <= s.length(); i++) printf("dp[%d] = %d\n", i, ways[i]);
    int ans[52][52];
    for(int i = 0; i < 52; i++){
        for(int j = 0; j < 52; j++) ans[i][j] = -1;
    }
    while(N--){
        cin >> a >> b;
        a--; b--;
        if(ans[getNum(s[a])][getNum(s[b])] != -1){
            cout << ans[getNum(s[a])][getNum(s[b])] << endl;
            continue;
        }

        int newdp[s.length() + 1];
        for(int i = 0; i <= s.length(); i++){
            newdp[i] = ways[i]; //the new dp init
        }
        for(int i = freqs[s[a]]; i <= s.length(); i++){
            newdp[i] -= newdp[i - freqs[s[a]]];
            while(newdp[i] < 0) newdp[i] += MOD;
            newdp[i] %= MOD;
        }

        //for(int i = 0; i <= s.length(); i++) printf("dp[%d] = %d\n", i, newdp[i]);
        if(s[a] != s[b]){
            for(int i = freqs[s[b]]; i <=  s.length(); i++){
                newdp[i] -= newdp[i - freqs[s[b]]];
                while(newdp[i] < 0) newdp[i] += MOD;
                newdp[i] %= MOD;
            }
            //for(int i = 0; i <= s.length(); i++) printf("dp[%d] = %d\n", i, newdp[i]);
        }
        //cout << W << ", " << newdp[s.length()/2] << endl;
        cout << 2 * W * newdp[s.length()/2] % MOD << endl;
        ans[getNum(s[a])][getNum(s[b])] = 2 * W * newdp[s.length()/2] % MOD;
        ans[getNum(s[b])][getNum(s[a])] = 2 * W * newdp[s.length()/2] % MOD;
    }

}
