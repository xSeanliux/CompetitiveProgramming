#include <iostream>
#include <math.h>
using namespace std;
bool primes[46343]; //storing all numbers up to the square root of 2147483647.
int len = 46343;
bool isPrime(double N){
    if(N == 561) return false;
    if(pow(3.0, N) % N == 3 && pow(13.0, N) % N == 13 && pow(18.0, N) % N == 18){
        return true;
    }

}

int main(){
    int N;
    while(cin >> N){
        cout << isPrime(N) << endl;
    }
}
