#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e5;
bool isPrime[maxN + 10];
vector<int> primes;

void getPrime(){
    for(int i = 0; i <= maxN; i++){
        isPrime[i] = i % 2;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i <= maxN; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && primes[j] * i <= maxN; j++){
            isPrime[primes[j] * i] = false;
            if(!(i % primes[j])) break;
        }
    }
}

vector<int> ans;
int N;

int main(){
    getPrime();
    cin >> N;
    ans.resize(N + 1);
    for(int i = 0; i < primes.size(); i++){
        if(primes[i] > N) break;
        for(int j = primes[i]; j <= N; j += primes[i]){
            ans[j] = i + 1;
        }
    }
    for(int i = 2; i <= N; i++) cout << ans[i] << " ";
}
