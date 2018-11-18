
#include <iostream>
using namespace std;


long long int N, primes[1480000], head, M = 2147483647;
bool isPrime[2147483648];
int nFactors = 0, cpI;

void initPrimes(){
    for(int i = 0; i < M; i++){
        isPrime[i] = (i % 2);
    }
    isPrime[0] = 0;
    isPrime[1] = 0;
    isPrime[2] = 1;
    primes[0] = 2;
    head = 1;
    for(long long int i = 3; i <= M; i+= 2){
        if(isPrime[i]){
            //cout << i << " is prime" << endl;
            primes[head] = i;
            head++;
            for(long long int j = i * i; j <= M; j += i){
                    isPrime[j] = 0;
                    //cout << j << " isn't" << endl;
            }
        }
    }
}

int main(){
    initPrimes();
    cout << "D" << endl;
    while(cin >> N){
        cout << N << endl;
        nFactors = 0;
        if(!N) return 0;
        printf("%d = ", N);
        if(N < 0){
            printf("-1");
            N = -N;
            nFactors++;
        }
        //cout << N << endl;

        if(N == 1){
            if(!nFactors)
                printf("1\n");
            else
                printf("\n");
        }
        cpI = 0;
        //cout << N << endl;
        while(N > 1){
            //cout << "Oh  " << primes[cpI] << endl;
            if(N % primes[cpI] == 0){
                //cout << "Oh" << endl;
                if(nFactors > 0){
                    printf(" x ");
                }
                printf("%d", primes[cpI]);
                N /= primes[cpI];
                nFactors++;
            } else {
                cpI++;
            }
        }
        printf("\n");

    }
}

