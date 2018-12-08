#include <iostream>
#include <map>
#include <vector>
#define N 10000000
using namespace std;

bool isPrime[N];
vector <int> primes;

void initPrime(){
    for(int i = 0 ; i < N; i++)
        isPrime[i] = i % 2;
    isPrime[1] = false;
    isPrime[2] = true;
    primes.push_back(2);
    for(int i = 3; i < N; i+=2){
        if(isPrime[i])
            primes.push_back(i);
        int L = primes.size();
        for(int j = 0; j < L && i * primes[j] < N; j++){
            isPrime[i * primes[j]] = false;
            if(!(i % primes[j])) break;
        }
    }
}

long long int n;

int main(){
    initPrime();
    while(cin >> n){
        if(n == 1) return 0;
        int pF = 0;
        int L = primes.size();
        for(int i = 0 ; i < L && n > 1; i++){
            while(!(n % primes[i])){
                pF++;
                n /= primes[i];
            }
        }
        if(n > 1)
            pF++;
        cout << pF << endl;
    }
}
