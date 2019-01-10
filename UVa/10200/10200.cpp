#include <iostream>
#include <vector>
#include <math.h>
#define N 20000
using namespace std;

bool isPrime[N + 45];
vector <int> primes;
int a, b, arr[N + 5];

int f(int n){
    return n*n + n + 41;
}

void getPrimes(){
    for(int i = 0 ; i < N; i++){
        isPrime[i] = i % 2;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    primes.clear();
    primes.push_back(2);
    for(int i = 3; i < N; i += 2){
        if(isPrime[i]){
            primes.push_back(i);
        }
        int l = primes.size();
        for(int j = 0; j < l && primes[j] * i < N; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

bool checkPrime(int K){
    if(K < N) return isPrime[K];
    int l = primes.size();
    for(int i = 0 ; i < l && 2 * primes[i] <= K; i++){
        if(!(K % primes[i])) return false;
    }
    return true;
}

int main(){
    getPrimes();
    arr[0] = 1;
    arr[1] = 2;
    for(int i = 2; i < 10001; i++){
        arr[i] = arr[i-1] + checkPrime(f(i));
        //cout << "arr[" << i << "] = " << arr[i]<< endl;
    }
    while(cin >> a >> b){
        if(!a) printf("%.2f\n", round(100*(arr[b]*100)/(b+1.0))/100.0);
        else printf("%.2f\n", round(100*(arr[b]*100 - arr[a-1]*100)/(b-a+1.0))/100.0);
    }
}
