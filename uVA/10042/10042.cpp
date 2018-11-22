#include <iostream>
#include <math.h>
#include <vector>
#define N 104735
using namespace std;
bool flag;

bool isPrime[N + 5];
vector <long long int> primes;

void getPrime(){
    primes.clear();
    for(int i = 0 ; i < N; i++)
        isPrime[i] = i % 2;
    isPrime[1] = false;
    isPrime[2] = true;
    primes.push_back(2);
    int L;
    for(int i = 2; i < N; i++){
        if(isPrime[i]){
            primes.push_back(i);
            //cout << i << " is prime" << endl;
        }
        L = primes.size();
        for(int j = 0 ; j < L && primes[j] * i < N; j++){
            isPrime[primes[j] * i] = false;
            if(i % primes[j] == 0) break;
        }
    }
}

int digSum(int n){
    int res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int primeFactorSum(int n){
    if(n < N && isPrime[n]) return -1;
    int L = primes.size(), res = 0, oriN = n;
    for(int i = 0 ; i < L; i++){
        while(!(n % primes[i])){
            n /= primes[i];
            res += digSum(primes[i]);
        }
    }
    if(oriN == n)
        return -1;

    if(n > 1){
        res += digSum(n);
    }
    return res;
}

bool isSmith(int n){
    return (primeFactorSum(n) == digSum(n));
}

int C, K;

int main(){
    getPrime();
    cin >> C;
    while(C--){
        cin >> K;
        for(int i = K + 1; i <= 1000000165; i++){
            //cout << "Checking " << i << endl;
            if(isSmith(i)){
                cout << i << endl;
                break;
            }
        }
    }

}
