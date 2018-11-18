#include <iostream>
using namespace std;

bool isPrime[2000];
int primes[1000];
int N, C;
int arr[1000];
void initPrimes(){
    for(int i = 0; i < 2000; i++){
        if(i % 2 == 0){
            isPrime[i] = false;
        } else {
            isPrime[i] = true;
        }
    }
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 3; i < 2000; i += 2){
        if(isPrime[i]){
            for(long long int j = i * i; j < 2000; j += i){
                isPrime[j] = false;
            }
        }
    }
    int head = 0;
    for(int i = 0; i < 2000; i++){
        if(isPrime[i]){
            primes[head] = i;
            head++;
        }
    }
}

int main(){
    initPrimes();
    while(cin >> N >> C){
        int h = 1;
        arr[0] = 1;
        for(int i = 0 ; i < N; i++){
            if(primes[i] <= N){
                arr[h] = primes[i];
                h++;

            } else {
                break;
            }
        }

        printf("%d %d:", N, C);
        if(h % 2 == 0){
            if(2*C >= h){
                for(int i = 0; i < h; i++){
                    printf(" %d", arr[i]);
                }
            } else {
                int start = (h - 2*C)/2;
                for(int i =  start; i < start + 2*C; i++){
                    printf(" %d", arr[i]);
                }
            }
        } else {
            if(2*C-1 >= h){
                for(int i = 0; i < h; i++){
                    printf(" %d", arr[i]);
                }
            } else {

                int start = (h - 2*C + 1)/2;
                for(int i = start; i < start + 2*C - 1; i++){
                    printf(" %d", arr[i]);
                }
            }
        }
        printf("\n\n");
    }
}

