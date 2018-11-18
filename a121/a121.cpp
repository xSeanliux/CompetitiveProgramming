#include <iostream>
using namespace std;

int len = 1003;
bool primes[1003];

bool isPrime(int n){
    if(n <= 1) return false;
    for(int i = 2; i < len; i++){
            if(primes[i] && n % i == 0 && n != i){ //if I is a prime and n is a multiple of it
                //cout << n << " % " << i << " == 0" << endl;
                return false;
            }

    }
    return true;

}

int main(){

    for(int i = 0; i < len; i++){
        primes[i] = true;
    }
    primes[0] = false;
    primes[1] = false;
    for(int i = 2; i*i < len; i++){
        if(primes[i]){
            //cout << "Found prime: " << i << endl;
            for(int j = i*i; j < len; j+=i){
                primes[j] = false;
            }
        }
    }
    int a, b, sum = 0;
    while(cin >> a >> b){

        for(int i = a; i <= b; i++){
            if(isPrime(i)){
                //cout << i << endl;
                sum++;
            }
        }
        cout << sum << endl;
        sum = 0;
    }

}
