#include <iostream>
using namespace std;

bool isPrime[20000000];
long long int primes[20000000];
long long int twins[107408][2];
int head = 0, N;
int L = 20000000;
void getPrimes(){
    for(long long int i = 0; i < L; i++){
        if(!(i % 2))
            isPrime[i] = false;
        else
            isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for(long long int i = 3; i < L; i+=2){
        if(isPrime[i]){
            //cout << "Found prime" << i << endl;
            primes[head] = i;
            head++;
            for(long long int j = i * i; j < L; j += i){
                isPrime[j] = false;
            }
        }
    }
    int tHead = 0;
    for(int i = 1; i < head; i++){
        if(primes[i] - primes[i-1] == 2){
            //cout << "found twin " << primes[i-1] << " " << primes[i] << endl;
            twins[tHead][0] = primes[i-1];
            twins[tHead][1] = primes[i];
            tHead++;
        }
    }
    //cout << tHead << " twins" << endl;
}

int main(){
    getPrimes();
    //cout << "Done " << endl;
    while(cin >> N){
        N--;
        printf("(%lld, %lld)\n", twins[N][0], twins[N][1]);
    }

}
