#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

vector<int> primes, pf, maxAns;
bool isPrime[maxN];

void init(){
    for(int i = 0; i < maxN; i++) isPrime[i] = true;
    isPrime[1] = false;
    for(int i = 2; i < maxN; i++){
        if(isPrime[i]) primes.push_back(i);
        for(int p : primes){
            if(p * i >= maxN) break;
            isPrime[p * i] = false;
            if(!(i % p)) break;
        }
    }
}

void getPF(int x){
    pf.clear();
    for(int p : primes){
        if(isPrime[x]){
            pf.push_back(x);
            break;
        }
        if(x == 1) break;
        if(!(x % p)){
            pf.push_back(p);
            while(!(x % p)) x /= p;
        }
    }
}

int N, x;

signed main(){
    ericxiao;
    init();
    cin >> N;
    maxAns.clear();
    maxAns.resize(maxN);
    fill(maxAns.begin(), maxAns.end(), 0);
    int ans = 1;
    for(int i = 0; i < N; i++){
        cin >> x;
        //cout << "FOR " << x << endl;
        if(x == 1) continue;
        pf.clear();
        getPF(x);
        int current = 1;
        for(int p : pf){
            current = max(current, maxAns[p] + 1);
            ans = max(ans, maxAns[p] + 1);
        }
        for(int p : pf){
            //cout << "ANS FOR " << p << " is now " << current << endl;
            maxAns[p] = current;
        }
        ans = max(ans, current);
    }
    cout << ans << endl;
}
