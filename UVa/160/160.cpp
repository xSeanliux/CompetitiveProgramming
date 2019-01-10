#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector <int> primes;
bool isPrime[1005];
int N, arr[105][105];

void initPrime(){
    for(int i = 0 ; i < 1005; i++){
        isPrime[i] = i % 2;
    }
    isPrime[1] = false;
    isPrime[2] = true;
    primes.push_back(2);
    for(int i = 3; i < 1005; i++){
        if(isPrime[i])
            primes.push_back(i);
        for(int j = 0; j < primes.size() && primes[j] * i < 1005; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

void dp(){
    initPrime();
    for(int i = 2; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            arr[i][j] = 0;
        }
    }
    arr[2][0] = 1;
    for(int i = 3; i <= 100; i++){
        for(int j = 0 ; j <= 100; j++){
            arr[i][j] = arr[i-1][j];
        }
        int _i = i;
        for(int j = 0; j < primes.size() && primes[j] <= _i; j++){
            while(!(_i % primes[j])){
                arr[i][j]++;
                _i /= primes[j];
            }
        }
    }
}

int main(){
    dp();
    while(cin >> N){
        if(!N) return 0;
        printf("%3d! =", N);
        for(int i = 0; i <= 100; i++){
            if(!arr[N][i]) break;
            if(!((i) % 15) && i) cout << endl << "      ";
            printf("%3d", arr[N][i]);

        }
        cout << endl;
    }
}
