#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;

int A, C, T;
bool isPrime[MAX];
vector <long long int> primes;

void getPrimes(){
    int M = MAX;
    for(int i = 0 ; i < M; i++){
        isPrime[i] = i & 1;
    }
    isPrime[2] = true;
    isPrime[1] = false;
    primes.push_back(2);
    for(int i = 3 ; i < M; i+=2){
        if(isPrime[i]){
            primes.push_back(i);
            //cout << "primes.size() = " << primes.size() << endl;
        }
        for(int j = 0; j < primes.size() && i * primes[j] < M; j++){
            isPrime[i * primes[j]] = false;
            if(!(i % primes[j])){
                break;
            }
        }
    }
}

long long int v(int p, int N){
    int res = 1;
    while(!(N % p)){
        N /= p;
        res *= p;
    }
    return res;
}


int main(){
    getPrimes();
    //cout << "Done" << endl;
    cin >> T;
    for(int i = 0; i < T; i++){
        scanf("%d %d", &A, &C);
        if(!(C % A)){
            int oriC = C;
            int B = 1, l = primes.size(), k;
            for(int i = 0 ; i < l && primes[i] <= oriC; i++){
                k = v(primes[i], C);
                C /= k;
                if(v(primes[i], A) < k){
                    B *= k;
                }
            }

            if(C > 1 && ( (C % A) || (A == 1) ) )
                B *= C;

            printf("%d\n", B);
            //cout << B << endl;
        } else {
            printf("NO SOLUTION\n");
        }
    }
}
