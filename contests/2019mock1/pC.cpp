#include <iostream>
#include "lib2078.h"
#include <cinttypes>
#include <vector>
#define int uint64_t
using namespace std;

const int maxC = 2100;
bool isPrime[maxC + 10];
vector<int> primes;
int N, Q, l, r, m;


inline void getPrime(){
    for(int i = 0; i < maxC; i++) isPrime[i] = true;
    for(int i = 2; i < maxC; i++){
        if(isPrime[i]) primes.push_back(i);
        for(auto j : primes){
            if(j * i >= maxC) break;
            isPrime[j * i] = false;
            if(!(i % j)) break;
        }
    }
}
int exp(int b, int e, int M){
    if(!b) return 0;
    if(!e) return 1;
    int res = exp(b, e/2, M);
    res = res * res % M;
    if(e % 2) res = b * res % M;
    return res;
}

uint64_t decrypt( uint64_t e, uint64_t N, uint64_t C, uint64_t k ){
    C %= N;
    for(int p = 1; p < N; p++){
        p %= N;
        //cout << "Trying " << p << endl;
        if(exp(p, e, N) == C) return p;
    }
}

//signed main(){
    //cout << decrypt(2, 5, 4, 100) << endl;
//}
