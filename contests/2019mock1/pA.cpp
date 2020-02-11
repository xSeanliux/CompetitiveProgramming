#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxC = 2e6 + 10;
bool isPrime[maxC];
vector<int> primes;
vector<pii> fact;
int N, Q, l, r, m;


inline void getPrime(){
    for(int i = 0; i < maxC; i++) isPrime[i] = true;

    for(int i = 2; i < maxC; i++){
        if(isPrime[i]) primes.push_back(i);
        for(auto j : primes){
            if(j * i >= maxC) break;
            isPrime[j * i] = false;
            if(!(i % j)) break;
        }
    }
}

inline void getFact(int x){
    //cout << "Factorizing" << endl;
    fact.resize(0);
    static pii re;
    for(int p : primes){
        //cout << "p = " << p << endl;
        if(p * p > x) break;
        if(!(x % p)){
            re = {p, 0};
            while(!(x % p)){
                re.S++;
                x /= p;
            }
            fact.push_back(re);
        }
    }
    if(x > 1) fact.push_back({x, 1});
}

inline int v(int x, int p){
    int res = 0;
    while(x){
        res += x/p;
        x /= p;
    }
    return res;
}



int main(){
    ericxiao;
    getPrime();
    cin >> Q;
    while(Q--){
        cin >> N;
        if(N < 2){
            cout << 0 << endl;
            continue;
        }
        getFact(N);
        int ans = 0;
        vector<pii> lef, ri;
        l = 0, r = N, m = (l + r) / 2; //r is good and l is not
        while(l + 1 < r){
            lef.resize(0); ri.resize(0);
            for(auto ex : fact){
                if(v(m, ex.F) < ex.S) ri.push_back(ex);
                else lef.push_back(ex);
            }
            if(ri.empty()){
                r = m;
            } else {
                l = m;
                swap(ri, fact);
            }
            m = (l + r) / 2;
        }
        ans = r;
        /*
        for(pii ex : fact){
            //ex.F^ex.S
            //cout << ex.F << "^" << ex.S << endl;
            l = 0, r = N, m = (l + r) / 2; //r is good and l is not
            while(l + 1 < r){
                if(v(m, ex.F) < ex.S) l = m;
                else r = m;
                m = (l + r) / 2;
            }
            //cout << "needs at least " <<r << "!" << endl;
            ans = max(ans, r);
        }
        */
        cout << ans << endl;
    }
}
