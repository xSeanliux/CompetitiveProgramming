#include <iostream>
#include <vector>
#define MAXN (int)1e5
using namespace std;

int N;
bool isPrime[MAXN];

vector<int> primes;

void getPrime(){
    for(int i = 0; i < MAXN; i++) isPrime[i] = i % 2;
    isPrime[2] = true;
    isPrime[1] = false;
    primes.push_back(2);
    for(int i = 3; i < MAXN; i += 2){
        if(isPrime[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i < MAXN; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

int main(){
    bool isNeg;
    primes.clear();
    getPrime();
    while(scanf("%d", &N) != EOF){
        if(!N) return 0;
        printf("%d = ", N);
        if(N < 0){
            isNeg = true;
            printf("-1 x ");
            N = -N;
        }
        for(int i = 0; primes[i] <= N && i < primes.size(); i++){
            if(N < MAXN && isPrime[N]){
                printf("%d", N);
                N = 1;
                break;
            } else {
                while(!(N % primes[i])){
                    printf("%d", primes[i]);
                    if(N != primes[i]) printf(" x ");
                    N /= primes[i];

                }
            }
        }
        if(N > 1){
            printf("%d", N);
        }
        printf("\n");
    }
}
