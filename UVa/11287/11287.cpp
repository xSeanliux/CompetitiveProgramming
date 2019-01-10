#include <iostream>
#include <vector>
#define LL long long
#define N 1000006
#define pb push_back
using namespace std;
LL int a, p;
bool isPrime[N];
vector <int> primes;

void getPrimes(){
    for(int i = 0; i < N; i++){
        isPrime[i] = i % 2;
    }
    isPrime[2] = true;
    isPrime[1] = false;
    primes.clear();
    primes.pb(2);
    for(int i = 3; i < N; i += 2){
        if(isPrime[i]){
            primes.pb(i);
        }
        int l = primes.size();
        for(int j = 0; j < l && primes[j] * i < N; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

bool checkPrime(LL int K){
    if(K < N) return isPrime[K];
    int l = primes.size();
    for(int i = 0; i < l && primes[i]*primes[i] <= K; i++)
        if(!(K % primes[i])) return false;
    return true;
}


int exp(LL int b, LL int e, LL int M){
    if(e == 1) return (b % M);
    else {
        LL int ans = 1, K = exp(b, e/2, M);
        ans = (K * K) % M;
        if(e % 2) ans *= b;
        return (ans % M);
    }
}

int main(){
    getPrimes();
    while(scanf("%lld%lld", &p, &a)){
        if(!(p | a)) return 0;
        //cout << exp(a, p, p) << endl;
        if(checkPrime(p)){
            printf("no\n");
        } else if(exp(a, p, p) == a){
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
}
