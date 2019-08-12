#pragma GCC optimize ("O3")
#include <iostream>
#include <vector>
#define MAXN 3000010
using namespace std;

bool isPrime[MAXN];
vector <int> primes;

void getPrime(){
    for(int i = 0; i < MAXN; i++){
        isPrime[i] = true;
    }
    for(int i = 2; i < MAXN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i < MAXN; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

void getNum(int &x){
    char c;
    x = 0;
    c = getchar();
    bool isNeg = false;
    if(c == '-') {
        isNeg = true;
        c = getchar();
    }
    for(;(c <= '9' && c >= '0'); c = getchar()){
        x = (x << 3) + (x << 1) + (c - '0');
    }
    if(isNeg) x *= -1;
}

int main(){
    getPrime();
    int ans[1000005], k, T;
    ans[0] = 0;
    for(int i = 1; i < 1000005; i++){
        ans[i] = ans[i-1] + isPrime[3*i + 7];
    }
    cin >> T;
    getNum(k);
    while(T--){
        getNum(k);
        printf("%d\n", ans[k]);
    }
}
