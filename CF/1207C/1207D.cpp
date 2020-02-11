#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int MOD = 998244353, maxN = 3e5;

int N, a, b, fact[maxN + 10];
vector<pii> vec;
vector<int> fir, sec;


inline int add(int a, int b){
    return (a + b) % MOD;
}

inline int sub(int a, int b){
    return (a - b + MOD) % MOD;
}

signed main(){
    ericxiao;
    fact[0] = 1;
    cin >> N;
    for(int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
    vec.resize(N);
    fir.resize(N);
    sec.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        vec[i] = {a, b};
        fir[i] = a;
        sec[i] = b;
    }
    int ans = fact[N];
    sort(vec.begin(), vec.end());
    sort(sec.begin(), sec.end());
    sort(fir.begin(), fir.end());
    int k = 1;
    for(int i = 0; i < N; i++){
        int l = 0;
        while(i + l < N && fir[i + l] == fir[i]){
            l++;
        }
        k = k * fact[l] % MOD;
        i += l - 1;
    }
    ans = sub(ans, k);
    k = 1;
    for(int i = 0; i < N; i++){
        int l = 0;
        while(i + l < N && sec[i + l] == sec[i]){
            l++;
        }
        k = k * fact[l] % MOD;
        i += l - 1;
    }
    ans = sub(ans, k);
    k = 1;
    bool flg = true;
    for(int i = 1; i < N; i++){
        if(vec[i].F < vec[i - 1].F || vec[i].S < vec[i - 1].S){
            flg = false;
            break;
        }
    }
    if(flg){
        for(int i = 0; i < N; i++){
            int l = 0;
            while(i + l < N && vec[i + l] == vec[i]){
                l++;
            }
            k = k * fact[l] % MOD;
            i += l - 1;
        }
        ans = add(ans, k);
    }

    cout << ans << endl;
}

