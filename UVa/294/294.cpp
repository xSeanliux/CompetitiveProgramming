#include <iostream>
#include <math.h>
#include <vector>
#define MAXN (int)(1e9)
#define tRN  (int)(1e3)
using namespace std;

bool isPrime[tRN + 10];
vector<int> primes;

void sieve(){
    for(int i = 0; i <= tRN; i++) isPrime[i] = i % 2;
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i <= tRN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i <= tRN; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

long long int modExp(int b, int e, int m){
    if(e == 1) return (long long int)b % m;
    long long int res = modExp(b, e/2, m);
    res = res * res % m;
    if(e % 2) res = res * b % m;
    return (int)res;
}

bool checkPrime(int y){
    if(y == 1) return false;
    if(!(y % 2)) return y == 2;
    int toCheck[7] = {2, 3, 5, 7, 11, 13, 17};
    int r = y - 1, s = 0;
    while(!(r % 2)){
        r /= 2;
        s++;
    }
    //cout << y << " = 2^" << s << " * " << r << " + 1" << endl;
    int x;
    for(int i = 0; i < 7; i++){
        if(toCheck[i] == y) return true;
        x = modExp(toCheck[i], r, y);
        //printf("%d^%d = %d (mod %d)\n", toCheck[i], r, x, y);
        bool flag = true;
        if(x == 1 || x == y - 1) continue;
        for(int j = 1; j < s; j++){
            x = (x * x) % y;
            //cout << "x is now " << x << endl;
            if(x == y-1) {
                flag = false;
                break;
            }
        }
        if(flag) return false;
    }
    return true;
}

int D_trial(int x){
    int res = 0;
    for(int i = 1; i * i <= x; i++){
        res += 2 * !(x % i) - (i * i == x);
    }
    //cout << x << " has " << res << " divisors" << endl;
    return res;
}

int D(int N){
    cout << "Running D(" << N << ")" << endl;
    if(N == 1) return 1;
    int x = 1, y = N;
    for(int i = 0; primes[i]*primes[i]*primes[i] <= N; i++){
        while(!(y % primes[i])){
            x *= primes[i];
            y /= primes[i];
        }
    }
    //cout << "OK" << endl;
    int X = D_trial(x), Y;
    cout << x << " has " << X << " divisors , to check = " << y << endl;
    if(y == 1){
        Y = 1;
    } else if(checkPrime(y)){
        Y = 2;
    } else if((int)sqrt(y) * (int)sqrt(y) == y && checkPrime((int)sqrt(y))){
        Y = 3;
    } else {
        Y = 4;
    }
    cout << endl;
    return X * Y;
}

int K, a, b, mv, mvat;

int main(){
    int x;
    sieve();
    cin >> K;
    while(K--){
        cin >> a >> b;
        mv = 0;
        for(int i = a ; i <= b; i++){
            cout << i << " " << D(i) << endl;
            if(D(i) > mv){
                mv = D(i);
                mvat = i;
            }

        }
        cout << "Between " << a << " and " << b << ", " << mvat << " has a maximum of " << mv << " divisors." << endl;
    }
}
