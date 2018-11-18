#include <iostream>
#include <math.h>
using namespace std;


bool isPrime[1000005];
int N;
int primes[291538], nPrimes;

void initPrimes(){
    nPrimes = 1;
    primes[0] = 2;
    for(int i = 0 ; i <= 1000000; i++ ){
        isPrime[i] = i % 2;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    for(long long int i = 3; i <= 1000000; i++){
        if(isPrime[i]){
            //cout << i << " is prime" << endl;
            primes[nPrimes] = i;
            nPrimes++;
            for(long long int j = 2 * i; j <= 1000000; j += i){
                //cout << j << " is not" << endl;
                isPrime[j] = false;
            }
        }
    }
    //cout << nPrimes << endl;
}

int main(){
    initPrimes();
    while(cin >> N){
        if(!N) return 0;
        //cout << "K = " << K << endl;
        int ans = 0;
        for(int i = 0 ; i < nPrimes && primes[i] <= N; i++){
            //cout << primes[i] << endl;
            if(primes[i] != 0 && !(N % primes[i])) ans++;
        }
        cout << N << " : " << ans << endl;
    }
}
