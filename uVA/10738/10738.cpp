#include <iostream>
#include <vector>
#define N 1000005
using namespace std;

vector<int> primes;
bool isPrime[N];
int mu[N], M[N], K;

void init()
{
    primes.clear();
    for(int i = 0 ; i < N; i++)
        isPrime[i] = i & 1;
    isPrime[2] = true;
    mu[1] = 1;
    for(int i = 2; i < N; i++){
        if(isPrime[i]){
            mu[i] = -1;
            primes.push_back(i);
            //cout << "mu(" << i << ") = -1 " << endl;
        }
        int L = primes.size();
        for(int j = 0; j < L && primes[j] * i < N; j++){
            isPrime[i * primes[j]] = false;
            mu[i * primes[j]] = mu[i] * mu[primes[j]];
            if(!(i % primes[j])){
                //cout << "mu(" << i * primes[j] << ") = 0" << endl;
                mu[i * primes[j]] = 0;
                break;
            }
            //cout << "mu(" << i * primes[j] << ") = " << mu[i * primes[j]] << endl;
        }
    }
    M[1] = mu[1];
    for(int i = 2; i < N; i++)
        M[i] = M[i-1] + mu[i];

}

int main(){
    init();
    while(cin >> K){
        if(!K) return 0;
        else
            printf("%8d%8d%8d\n", K, mu[K], M[K]);
    }
}
