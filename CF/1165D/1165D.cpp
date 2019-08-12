#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#define int long long int
using namespace std;

const int maxN = 1e6;
vector<int> primes;
map<int, int> pows;
bool isPrime[maxN + 10];
int T, K, d;

void getPrime(){
    for(int i = 0; i < maxN; i++) isPrime[i] = i & 1;
    isPrime[1] = false;
    isPrime[2] = true;
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && primes[j] * i < maxN; j++){
            isPrime[i * primes[j]] = false;
            if(!(i % primes[j])) break;
        }
    }
}

void run(int x){
    for(int i : primes){
        if(i*i > x) break;
        int p = 0;
        if(!(x % i)){
            while(!(x % i)){
                p++;
                x /= i;
            }
            pows[i] = max(p, pows[i]);
        }
    }
    if(x > 1 && !pows.count(x)){
        pows[x] = 1;
    }
}


signed main(){
    getPrime();
    cin >> T;
    while(T--){
        pows = map<int, int>();
        cin >> K;
        for(int i = 0; i < K; i++){
            cin >> d;
            run(d);
        }
        int totalDivs = 1;
        for(auto p : pows){
            //cout << p.first << " " << p.second << endl;
            totalDivs *= (p.second + 1);
            if(totalDivs > K + 2){
                cout << -1 << endl;
                break;
            }
        }
        if(totalDivs < K + 2 || totalDivs > K + 2){
            cout << -1 << endl;
            break;
        }
        int ans = 1;
        for(auto p : pows){
            ans *= pow(p.first, p.second);
        }
        if(pows.size() == 1) ans *= pows.begin()->first;
        cout << ans << endl;
    }

}
