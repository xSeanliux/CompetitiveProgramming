#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxP = 1e2;

vector<int> primes;
bool isPrime[maxP];

inline void sieve() {
    fill(isPrime, isPrime + maxP, 1);
    isPrime[1] = false;
    for(int i = 2; i < maxP; i++) {
        if(isPrime[i]) primes.push_back(i);
        for(int j = i; j < maxP; j += i) isPrime[j] = false;
    }
}

int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);
}

signed main() {
    int N;
    cin >> N;
    sieve();
    int curN = 1, num = 1, den = 1;
    for(int p : primes) {
        if(curN <= N / p) {
            //cout << " adding in " << p << endl;
            num *= (p - 1);
            den *= (p);
            curN *= p;
        }
    }
    num = den - num;
    int g = gcd(den, num);
    den /= g;
    num /= g;
    cout << num << "/" << den << endl;
}
