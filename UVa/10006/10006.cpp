#pragma GCC optimize ("O3")
#include <iostream>
#include <math.h>
using namespace std;
/*
int a, n;
bool primes[70000];
int chars[1000];
int head;
int modPow(int b, int e, int m){
    long long int r = b;
    while(!(e % 2)){
        r *= r;
        r %= m;
        e /= 2;
    }
    for(int i = 1; i < e; i++){
        if(!r) return 0;
        r *= b;
        r %= m;
    }
    return r;
}

void getPrimes(){
    primes[0] = false;
    primes[1] = false;
    for(long long int i = 3; i < 70000; i+=2){
        if(primes[i]){
            //cout << i << " is prime" << endl;
            for(long long int j = i*i; j < 70000; j += i){
                //cout << "but " << j << " isn't" << endl;
                primes[j] = false;
            }
        }
    }
}

int main(){
    cout << modPow(10, 2, 60);
    head = 0;
    for(int i = 0; i < 70000; i++){
        primes[i] = true;
        if(i > 2 && !(i%2)) primes[i] = false;
    }
    getPrimes();
    for(int i = 1; i < 70000; i++){ // the N
        if(primes[i]) {
            //cout << i << " is prime" << endl;
            continue;
        } else {

            //cout << "Checking " << i << endl;
            for(int k = 2; k < i; k++){ // the a
                if(modPow(k, i, i) != k){
                    break;
                } else if(k == i-1){
                    chars[head] = i;
                    head++;
                    cout << "Found" << i << endl;
                }
            }
        }

    }
    cout << "Finished " << endl;
    for(int i = 0; i < head; i++){
        cout << chars[i] << endl;
    }
}

*/

void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }


int N;
int main(){
    while(true){
        fastscan(N);
        if(!N) return 0;
        else if(N == 561 || N == 1105 || N == 1729 || N == 2465 || N == 2821 || N == 6601 || N == 8911 || N == 10585|| N == 15841 || N == 29341 || N == 41041 || N == 46657 || N == 52633 || N == 62745 || N == 63973){
            printf("The number %d is a Carmichael number.\n", N);
        } else {
            printf("%d is normal.\n", N);
        }
    }
}

