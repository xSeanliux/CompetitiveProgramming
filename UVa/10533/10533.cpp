#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6;

bool isPrime[MAXN + 10];
vector<int> primes;

void getPrime(){
    primes.clear();
    for(int i = 0; i <= MAXN; i++) isPrime[i] = i % 2;
    isPrime[2] = true;
    isPrime[1] = false;
    isPrime[0] = false;
    for(int i = 2; i <= MAXN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i <= MAXN; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

int digSum(int x){
    int ans = 0;
    while(x){
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

int ans[MAXN + 10], T, a, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i <= MAXN; i++) ans[i] = 0;
    getPrime();
    for(int p : primes){
        ans[p] = isPrime[digSum(p)];
    }
    for(int i = 1; i <= MAXN; i++){
        ans[i] += ans[i-1];
    }
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout << ans[b] - ans[a - 1] << endl;
    }
}
