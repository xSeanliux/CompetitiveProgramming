#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e6 + 10;

vector<int> primes;
bool isPrime[maxN];

void sieve(){
    for(int i = 0; i < maxN; i++) isPrime[i] = true;
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j : primes){
            if(i * j >= maxN) break;
            isPrime[i * j] = false;
            if(!(i % j)) break;
        }
    }
}

int gcd(int a, int b){
    return (!b ? a : gcd(b, a % b));
}

int A, B;

signed main(){
    sieve();
    cin >> A >> B;
    int g = gcd(A, B), cnt = 1;
    for(int p : primes){
        if(p * p > g) break;
        if(!(g % p)){
            cnt++;
            while(!(g % p)) g /= p;
        }
    }
    cnt += (g > 1);
    cout << cnt << endl;
}
