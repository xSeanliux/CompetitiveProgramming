#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e5;

bool isPrime[maxN + 10];
vector<int> primes;
int N;

void initPrime(){
    for(int i = 0; i <= maxN; i++) isPrime[i] = true;
    isPrime[1] = false;

    for(int i = 2; i <= maxN; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
        for(int p : primes){
            if(p * i > maxN) break;
            isPrime[p * i] = false;
        }
    }
}

int main(){
    initPrime();
    cin >> N;
    if(N <= 2){
        cout << 1 << endl;
        for(int i = 0; i < N; i++){
            cout << 1 << " \n"[i == N - 1];
        }
        return 0;
    }
    cout << 2 << endl;
    for(int i = 2; i <= N + 1; i++){
        cout << (isPrime[i] + 1) << " \n"[i == N + 1];
    }
}
