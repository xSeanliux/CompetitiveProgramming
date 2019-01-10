#include <iostream>
#include <set>
#include <vector>
#include <bitset>
#define N 10000
#define MAX (unsigned long long int)18446744073709551615
using namespace std;

bitset <N> isPrime;
set <unsigned long long int> powers;
vector<unsigned long long int> primes, notPrime;


unsigned long long int pow(unsigned long long int b, unsigned long long int e){
    if(e == 1) return b;
    unsigned long long int r = pow(b, e/2);
    if(r == -1) return 0;
    if(e % 2 && r*b > MAX/r) return 0;
    if(!(e % 2) && r > MAX/r) return 0;
    unsigned long long int ans = r * r;
    if(e % 2) ans *= b;
    return ans;
}


void initPrime(){
    for(int i = 0; i < N; i++){
        isPrime[i] = i % 2;
    }
    isPrime[2] = true;
    isPrime[1] = false;
    for(int i = 3; i < N; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
        int l = primes.size();
        for(int j = 0; primes[j]*i < N && j < l; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
    for(int i = 1; i < N; i++){
        if(!isPrime[i]){
            notPrime.push_back(i);
        }
    }
    int l = notPrime.size();
    for(unsigned long long int i = 2; i < ((1 << 16) + 2); i++){
        unsigned long long int currentPow = notPrime[1];
        //powers.insert((unsigned long long int)pow(i, currentPow));
        if(!powers.count((unsigned long long int)pow(i, currentPow))){
            //printf("%llu ^ %llu = %llu\n",i, currentPow, (unsigned long long int)pow(i, currentPow));
            powers.insert((unsigned long long int)pow(i, currentPow));
        }
        for(int j = 2; j < l; j++){
            if((unsigned long long int)pow(i, notPrime[j]) <= 0 || (unsigned long long int)pow(i, notPrime[j] - currentPow) > MAX/(unsigned long long int)pow(i, currentPow)) break;
            powers.insert((unsigned long long int)pow(i, notPrime[j]));
            //printf("%llu ^ %llu = %llu\n", i, notPrime[j], (unsigned long long int)pow(i, notPrime[j]));
            currentPow = notPrime[j];
        }
    }
    for(set<unsigned long long int>::iterator i = powers.begin(); i != powers.end(); i++){
        if(!*i){
            printf("1\n");
            continue;
        }
        printf("%llu\n", *i);
    }
}

int main(){
    initPrime();
}
