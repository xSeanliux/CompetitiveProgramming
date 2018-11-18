#include <iostream>
#include <vector>
#include <math.h>
#define n 1000000
using namespace std;


bool isPrime[n];
vector <long long int> primes;
long long int N;

void initPrime(){
    for(int i = 0 ; i < n; i++)
        isPrime[i] = i % 2;
    isPrime[1] = false;
    isPrime[2] = true;
    primes.push_back(2);
    for(int i = 3 ; i < n; i+=2){
        if(isPrime[i]){
            primes.push_back(i);
        }
        int L = primes.size();
        for(int j = 0; j < L && primes[j] * i < n; j++){
            isPrime[ primes[j] * i ] = false;
            if(!(i % primes[j]))
                break;
        }
    }
}



int main(){
    initPrime();
    cin >> N;
    int ans = 0;
    long long int L = primes.size();
    bool flag;
    if(!(N % 2)){
        cout << N/2 << endl;
        return 0;
    } else {
        for(int i = 1 ; i < L; i++){
            if(!(N % primes[i])){
                N -= primes[i];
                cout << N/2 + 1 << endl;
                return 0;
            } else if(i == L-1){
                cout << 1 << endl;
                return 0;
            }
        }
    }
}
