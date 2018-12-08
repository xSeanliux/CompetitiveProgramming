#include <iostream>
#include <vector>
#include <math.h>
#define N 1000000
using namespace std;


long long int denom;
vector<int> primes;
vector<bool> isPrime;

void go(){
    for(long long int i = 0 ; i <= N; i++){
        isPrime[i] = i % 2;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    for(long long int i = 2; i <= N; i++){
        //cout << "i = " << i << endl;
        if(isPrime[i]){
            //cout << "Prime: " << i << endl << endl;
            primes.push_back(i);
        }
        bool flag = true;
        for(long long int j = 0; j < primes.size() && primes[j] * i <= N; j++){
            isPrime[ i * primes[j] ] = false;
            //cout << "primes[" << j << "] = " << primes[j] << endl;
            //cout << "primes[" << j + 1 << "] = " << primes[j + 1] << endl;
            //cout << i * primes[j] << " is not prime" << endl;
            if(!(i % primes[j]))
                break;
        }
    }
}

int phi(int n){
    long long int ans = n;
    for(int i = 0 ; i < primes.size(); i++){
        if(!(n % primes[i])){
            //cout << "Found factor: " << primes[i] << endl;
            ans /= primes[i];
            ans *= primes[i] - 1;
            while(!(n % primes[i])){
                n /= primes[i];
            }
        }
    }
    if(n > 1){
        ans /= n;
        ans *= n - 1;
    }
    return ans;
}


int main(){
    isPrime.reserve(N + 20);
    go();
    //cout << "Done" << endl;
    while(cin >> denom){
        if(!denom) return 0;
        cout << phi(denom) << endl;
    }
}
