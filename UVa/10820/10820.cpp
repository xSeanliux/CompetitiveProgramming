#include <iostream>
#include <vector>
#include <math.h>
#define lli long long int
#define MAX 50000
using namespace std;

vector<lli> primes;
lli phi[MAX + 5], phipre[MAX + 5];
bool isPrime[MAX + 5];

void init(){
    for(int i = 0; i <= MAX; i++){
        isPrime[i] = i % 2;
        phi[i] = -1;
    }
    isPrime[2] = true;
    isPrime[1] = false;
    phi[1] = 1;
    for(lli i = 2; i <= MAX; i++){
        if(isPrime[i]){
            primes.push_back(i);
            //printf("phi[%d] = %lld\n", i, i-1);
            phi[i] = i - 1;
        }
        for(int j = 0; j < primes.size() && primes[j] * i <= MAX; j++){
            isPrime[i * primes[j]] = false;
            //printf("Not primes: %d\n", i * primes[j]);
            if(!(i % primes[j])){
                lli pow = 1, left = i * primes[j];
                while(!(left % primes[j])){
                    pow *= primes[j];
                    left /= primes[j];
                }
                if(phi[pow] == -1){
                    phi[pow] = pow*(primes[j] - 1)/primes[j];
                }
                phi[i * primes[j]] = phi[pow] * phi[left];
                //printf("A: So phi[%d] = phi[%lld] * phi[%lld] = %lli * %lli\n", i * primes[j], pow, left, phi[pow], phi[left]);
            } else {
                //printf("B: So phi[%d] = %lld\n", i * primes[j], phi[i * primes[j]]);
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }

    phipre[1] = phi[1];
    for(int i = 2; i <= MAX; i++) phipre[i] = phi[i] + phipre[i-1];
}

int main(){
    int n;
    init();
    while(cin >> n) {
        if(!n) return 0;
        printf("%lld\n", 2* phipre[n] - 1);
    }
}
