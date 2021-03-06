#include <iostream>
#include <math.h>
#include <ctime>
#include <map>
#define ulli unsigned __int128
using namespace std;

ulli A = 1, oriN, N, T;
ulli toCheck[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 37};
map<ulli, int> ps;

ulli gcd(ulli a, ulli b){
    return (!b) ? a : gcd(b, a % b);
}

ulli f(ulli x){
    return (x * x + 1) % N;
}


ulli modexp(ulli b, ulli e, ulli m){
    if(e == 1) return b % m;
    ulli res = modexp(b, e/2, m);
    res = (res * res) % m;
    if(e % 2) res = (res * b) % m;
    return res;
}

bool isPrime(ulli K){ //Miller-Rabin
    if(K == 3 || K == 2) return true;
    ulli r = 0, d = K-1;
    while(!(d % 2)){
        r++;
        d /= 2;
    }
    for(int i = 0; i < 8 && toCheck[i] <= K-2; i++){
        ulli x = modexp(toCheck[i]%K, d, K);
        if(x == 1 || x == K-1) continue;
        bool flag = true;
        for(int j = 0; j < r; j++){
            x = (x * x) % K;
            if(x == K-1){
                flag = false;
                break;
            }
        }
        if(flag) return false;
    }
    return true;
}

int findFactor(ulli N){ //pollard rho
    if(N == 1 || isPrime(N));
    if(!(N % 2)) return 2;
    ulli a, b, res = 1;
    bool flag = false;
    srand(time(NULL));
    while(true){
        a = (rand()%(N-2)) + 2;
        b = a;
        A = rand() + 1;
        do{
            b = f(f(b));
            a = f(a);
            res = gcd(N, max(a, b) - min(a, b));
            if(res > 1){
                if(res == N) break;
                return res;
                flag = true;
            }
        } while(a != b);
    }
}

void factorize(ulli N){
    if(N == 1) return;
    if(isPrime(N)){
        if(ps.count(N)){
            ps[N]++;
        } else {
            ps.insert(pair<ulli, int>(N, 1));
        }
        return;
    }
    ulli res = findFactor(N);
    factorize(res);
    factorize(N/res);
}



int main(){
    while(scanf("%llu", &N)){
        ps.clear();
        time_t st, et;
        time(&st);
        factorize(N);
        time(&et);
        printf("%llu ms taken\n", et - st);
        printf("%llu =", N);
        for(auto i = ps.begin(); i != ps.end(); i++){
            if(i != ps.begin()){
                printf(" *");
            }
            printf(" %llu", i->first);
            if(i->second > 1){
                printf("^%d", i->second);
            }
        }
        printf("\n");
    }
}
