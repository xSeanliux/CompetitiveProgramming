#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N;
string s;

bool isPrime[1500000];

void initPrimes(){
    for(int i = 2 ;i < 1500000; i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(long long int i = 0; i < 1500000; i++){
        if(isPrime[i]){
            for(long long int j = i*i; j < 1500000; j += i){
                isPrime[j] = false;
            }
        }
    }
}

int main(){
    initPrimes();
    while(cin >> s){
        int K = stoi(s);
        reverse(s.begin(), s.end());
        int K_ = stoi(s);
        if(isPrime[K]){
            if(isPrime[K_] && K != K_){
                printf("%d is emirp.\n", K);
            } else {
                printf("%d is prime.\n", K);
            }
        } else {
            printf("%d is not prime.\n", K);
        }
    }
}


