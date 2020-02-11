#include <iostream>
#include <vector>
#include <math.h>
#define N 200001
using namespace std;

long long int pHead = 0, n;
vector<int> primes;
vector <int>phi;
vector<bool> isPrime;
long long int ans[N+5], sum[N+5];


void go(){
    for(long long int i = 0 ; i < N; i++){
        isPrime[i] = (i % 2);
        sum[i] = 0;
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
            sum[i] = i-1;
        }
        bool flag = true;
        for(long long int j = 0; j < pHead && flag && i * primes[j] <= N; j++){
                isPrime[i * primes[j]] = false;
                phi[ i * primes[j] ] = phi[i] * phi[ primes[j] ];
                if(!(i % primes[j])){
                    int maxPow = 1, I = i * primes[j];
                    while(!(I % primes[j])){
                        maxPow *= primes[j];
                        I /= primes[j];
                    }
                    if(I == 1){
                        phi[i * primes[j]] = maxPow - maxPow/primes[j];
                    } else {
                        phi[i * primes[j]] = phi[maxPow] * phi[I];
                    }
                    sum[i*primes[j]] += phi[i] * primes[j];
                    flag = false;
                    break;
                }
                sum[i*primes[j]] += phi[i] * primes[j];
                printf("sum[%d] = %lld\n", i * primes[j], phi[i] * primes[j]);
        }
    }
    ans[2] = sum[2];
    for(int i = 3; i < N; i++){
        ans[i] = sum[i] + ans[i-1];
        printf("ans[%d] = %lld\n", i, ans[i]);
    }
}


int main(){
    primes.reserve(N);
    phi.reserve(N);
    isPrime.reserve(N);
    phi[1] = 1;
    go();
    //cout << "Done" << endl;
    /*
    for(int i = 1; i <= N; i++){
        cout << "phi(" << i << ") = " << phi[i] << endl;
    }
    */
    while(cin >> n){
        if(!n) return 0;
        printf("%lld\n", ans[n]);
    }

    return 0;
}

