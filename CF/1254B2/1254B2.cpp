#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 10, INF = 1e18;

int N, vals[maxN], sum = 0, ans = INF;

vector<int> primes;
bool isPrime[maxN];

inline int add(int a, int b, int m){
    return (a + b > m) ? (a + b - m) : a + b;
}

inline int sub(int a, int b, int m){
    return (a - b < 0) ? (a - b + m) : a - b;
}

void getPrime(){
    fill(isPrime, isPrime + maxN, true);
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(p * i >= maxN) break;
            isPrime[p * i] = false;
            if(!(i % p)) break;
        }
    }
}

int getAns(int x){
    int nvals[maxN], res = 0, mv, k;
    for(int i = 0; i < N; i++) nvals[i] = vals[i] % x;
    for(int i = 0; i < N; i++){
        if(nvals[i] < x - nvals[i]){
            for(int j = i + 1; j < N && nvals[i]; j++){
                k = min(nvals[i], x - nvals[j]);
                nvals[j] = add(nvals[j], k, x);
                nvals[i] = sub(nvals[i], k, x);
                res += (j - i) * k;
            }
        } else {
            for(int j = i + 1; j < N && nvals[i] < x; j++){
                k = min(x - nvals[i], vals[j]);
                nvals[j] = sub(nvals[j], k, x);
                nvals[i] = add(nvals[i], k, x);
                res += (j - i) * k;
            }
        }
    }
    return res;
}

signed main(){
    ericxiao;
    getPrime();
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> vals[i];
        sum += vals[i];
    }
    if(sum == 1){
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    for(int p : primes){
        if(!(sum % p)){
            ans = min(ans, getAns(p));
            cnt++;
        }
    }
    if(!cnt) ans = getAns(sum);
    cout << ans << endl;
}
