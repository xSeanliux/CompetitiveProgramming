#include <iostream>
#include <math.h>
using namespace std;

bool isPrime[40000];
long long int Q;

void getp(){
    for(int i = 0 ; i < 40000; i++){
        isPrime[i] = i % 2;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 3 ; i < 40000; i+=2){
        if(isPrime[i]){
            for(int j = i * i; j < 40000; j += i){
                isPrime[j] = false;
            }
        }
    }
}

long long tot(long long int N){
    if(N <= 1) return 1;
    if(N < 39999 && isPrime[N]) return N - 1;
    for(int i = 2; i < 40000; i++){
        if(isPrime[i] && !(N % i)){
            int k = 0;
            while(!(N % i)){
                N /= i;
                k++;
            }
            //cout << i << endl;
            return tot(N) * (pow(i, k) - pow(i, k-1));
        } else if(i == 39999){
            return N - 1;
        }
    }
}

int main(){
    getp();
    while(cin >> Q){
        if(!Q) return 0;
        if(Q == 1) printf("0\n");
        else
            printf("%lld\n", tot(Q));
    }
}
