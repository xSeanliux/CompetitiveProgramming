#include <iostream>
#include <vector>
#include <math.h>
#define MAX 1000006
using namespace std;

vector <int> primes;
bool isPrime[1000006];

void getPrime(){
    for(int i = 0 ; i < MAX; i++){
        isPrime[i] = i % 2;
    }
    isPrime[2] = true;
    primes.push_back(2);
    for(int i = 3; i < MAX; i += 2){
        if(isPrime[i]){
            primes.push_back(i);
        }
        int l = primes.size();
        for(int j = 0; j < l && primes[j] * i < MAX; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}
int N;
int main(){
    getPrime();
    cin >> N;
    if(N == 1){
        cout << "1 0" << endl;
        return 0;
    }
    int l = primes.size(), ans = 1, currentPow, largestPow = 0;
    for(int i = 0 ; i < l && primes[i] <= N; i++){
        if(!(N % primes[i])) {
            ans *= primes[i];
            currentPow = 0;
            int ori = N;
            while(!(ori % primes[i])){
                ori /= primes[i];
                currentPow++;
            }
            largestPow = max(largestPow, currentPow);
        }
    }
    cout << ans;
    if(largestPow == 1){
        cout << " " << 0 << endl;
    } else {
        bool needToMult = 0;
        for(int i = 0 ; i < l && primes[i] <= N; i++){
            if(!(N % primes[i])) {
                ans *= primes[i];
                currentPow = 0;
                int ori = N;
                while(!(ori % primes[i])){
                    ori /= primes[i];
                    currentPow++;
                }
                if(currentPow != largestPow){
                    needToMult = true;
                    break;
                }
            }
        }
        if(!needToMult && ceil(log2(largestPow)) - log2(largestPow) < 0.00001)
            cout << " " << ceil(log2(largestPow)) << endl;
        else
            cout << " " << 1 +ceil(log2(largestPow)) << endl;
    }

}
