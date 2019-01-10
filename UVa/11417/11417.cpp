#include <iostream>
#include <vector>
#include <math.h>
#define N 100000000
using namespace std;

long long int pHead = 0, n;
vector<int> primes;
vector <int>phi;
vector<bool> isPrime;



void go(){
    for(long long int i = 0 ; i < N; i++){
        isPrime[i] = (i % 2);
    }
    isPrime[1] = false;
    isPrime[2] = true;
    for(long long int i = 2 ; i < N; i++){
        //cout << "i = " << i << endl << endl << endl;
        //cout << "phi[9] = " << phi[9] << endl;

        if(isPrime[i]){
            primes[pHead] = i;
            pHead++;
            //primes.insert(i);
            //cout << "Prime: " << i << endl;
            phi[i] = i-1;
        }
        bool flag = true;
        for(long long int j = 0; j < pHead && flag && i * primes[j] <= N; j++){
                isPrime[i * primes[j]] = false;
                //cout << "phi[" << i * primes[j] << "] = " << "phi[" << i << "] * phi[" << primes[j] << "] = " <<  phi[i] << " * " << primes[j]<< endl;
                phi[ i * primes[j] ] = phi[i] * phi[ primes[j] ];
                if(!(i % primes[j])){
                    int maxPow = 1, I = i * primes[j];
                    while(!(I % primes[j])){
                        maxPow *= primes[j];
                        I /= primes[j];
                    }
                    if(I == 1){
                        phi[i * primes[j]] = maxPow - maxPow/primes[j];
                        //cout << "phi[" << i * primes[j] << "] = " << maxPow - (maxPow)/primes[j] << endl;
                    } else {
                        //cout << "phi[" << i * primes[j] << "] = " << maxPow - maxPow/primes[j] << endl;
                        phi[i * primes[j]] = phi[maxPow] * phi[I];
                    }
                    flag = false;
                    break;
                }
        }
    }
}


int main(){
    primes.reserve(N);
    phi.reserve(N);
    isPrime.reserve(N);
    phi[1] = 1;
    long long int ans = 0;
    go();
    cout << "Done" << endl;
    /*
    for(int i = 1; i <= N; i++){
        cout << "phi(" << i << ") = " << phi[i] << endl;
    }
    */
    while(cin >> n){
        if(!n ) return 0;
        ans = 0;
        for(int i = 1 ; i <= n; i++){
            ans += floor(n/i) * floor(n/i) * phi[i];
        }
        ans -= n*(n+1)/2;
        ans /= 2;
        cout << ans << endl;
    }

    return 0;
}
