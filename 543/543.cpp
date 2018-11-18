#include <iostream>
#include <math.h>
using namespace std;

int N;
bool isPrime[1000000 + 5];
int primes[1000000 + 5];
int head;
void readyPrimes(){
    int lim = 1000000 + 5;
    for(int i = 0 ; i < lim; i++){
        isPrime[i] = (i % 2);

    }
    //cout << "A" << endl;
    isPrime[1] = false;
    isPrime[2] = false;
    for(long long int i = 0 ; i < lim ; i++){
        if(isPrime[i]){
            for(long long int j = i * i; j < lim; j += i){
                isPrime[j] = false;
            }
        }
    }
    head = 0;
    for(int i = 0 ; i< lim; i++)
    {
        if(isPrime[i]){
            primes[head] = i;
            head++;
        }
    }
}

int main(){
    readyPrimes();
    while(cin >> N){
        if(!N) return 0;
        else {
            for(int i = 0 ; i < N; i++){
                if(isPrime[N - primes[i]]){
                    printf("%d = %d + %d\n", N, primes[i], N-primes[i]);
                    break;
                }
            }
        }
    }
}
