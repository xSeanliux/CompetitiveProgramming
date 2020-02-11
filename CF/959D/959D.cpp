#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e7 + 10;

int n, t, ans;
bool has = false, visited[maxN], isPrime[maxN], usedPrime[maxN];
vector<int> primes;

void getPrime(){
    for(int i = 0; i < maxN; i++) isPrime[i] = true;
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int j : primes){
            if(i * j >= maxN) break;
            isPrime[i * j] = false;
            if(!(i % j)) break;
        }
    }
}

int main(){
    getPrime();
    ericxiao;
    cin >> n;
    bool isDone = false;
    for(int i = 0; i < n && !isDone; i++){
        cin >> t;
        if(has){
            //if(n > 5000) cout << "A " << endl;
            for(int p : primes){
                if(!usedPrime[p]){
                    cout << p << " ";
                    i++;
                }
                if(i == n){
                    isDone = true;
                    break;
                }
            }
        } else {
            for(int k = t; k < maxN; k++){
                if(!visited[k]){
                    ans = k;
                    if(k > t) has = true;
                    break;
                }
            }
            cout << ans << " ";
            for(int p : primes){
                if(p * p > ans) break;
                if(!(ans % p) && !usedPrime[p]){
                    for(int j = p; j < maxN; j += p) visited[j] = true;
                    usedPrime[p] = true;
                    while(!(ans % p)) ans /= p;
                }
            }
            if(ans > 1 && !usedPrime[ans]){
                usedPrime[ans] = true;
                for(int j = ans; j < maxN; j += ans) visited[j] = true;
            }
        }

    }
}
