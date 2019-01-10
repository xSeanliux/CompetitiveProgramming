#include <iostream>
#include <vector>
#include <bitset>
#define N 10000000
using namespace std;
//By S
bitset<N+5> isPrime;
vector <int> primes;
int ans[N + 5];

void getPrimes(){
    for(int i = 0; i < N + 5; i++){
        isPrime[i] = mi % 2;
    }
    isPrime[2] = true;
    isPrime[1] = false;
    primes.push_back(2);
    ans[1] = 0;
    ans[2] = 1;
    for(int i = 3; i < N + 5; i++){
        ans[i] = ans[i-1];
        if(isPrime[i]){
            primes.push_back(i);
            ans[i]++;
        }
        int l = primes.size();
        for(int j = 0; j < l && primes[j] * i < N; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
        //printf("%d primes <= than %d\n", ans[i], i);
    }
}

int n, m;

int main(){
    getPrimes();
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        cout << ans[m] << endl;
    }
}
