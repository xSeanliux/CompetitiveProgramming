#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1120;
vector<int> primes;
bool isPrime[MAXN + 10];

long long int ways[15][MAXN + 10];

void getPrime(){
    primes.clear();
    for(int i = 0; i <= MAXN; i++) isPrime[i] = i % 2;
    isPrime[2] = true;
    isPrime[1] = false;
    for(int i = 2; i <= MAXN; i++){
        if(isPrime[i])
            primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i <= MAXN; j++){
            primes[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

void getDp(){

}

int main(){

}
