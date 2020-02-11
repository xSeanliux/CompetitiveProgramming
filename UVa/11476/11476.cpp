#pragma GCC optimize ("O3")
#include <iostream>
#include <math.h>
#include <map>
#include <string.h>
#define ulli unsigned __int128 //hehe massive numbers are allowed now
using namespace std;
ulli A = 1, oriN, N, seed = 101;
ulli toCheck[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 37};
map<ulli, ulli> ps;

int T;

ulli Rand(){
    return seed = seed * seed + 13;
}

ulli toULLI(string s){
    ulli r = 0;
    for(char c : s){
        r *= 10;
        r += (c - '0');
    }
    return r;
}

string toStr(ulli x){
    string s = "";
    while(x){
        s = (char)((x % 10) + '0') + s;
        x /= 10;
    }
    return s;
}

ulli f(ulli x){
    return (x*x + A) % N;
}

ulli gcd(ulli a, ulli b){
    //cout << "Running gcd(" << toStr(a) << ", " << toStr(b) << ")" << endl;
    return (!b) ? a : gcd(b, a % b);
}

ulli modexp(ulli b, ulli e, ulli m){
    if(e == 1) return b % m;
    ulli res = modexp(b, e/2, m);
    res = (res * res) % m;
    if(e % 2) res = (res * b) % m;
    return res;
}

bool isPrime(ulli K){ //Miller-Rabin
    if(K == 3 || K == 2) return true;
    if(!(K % 2)) return false;
    ulli r = 0, d = K-1;
    while(!(d % 2)){
        r++;
        d /= 2;
    }
    for(ulli i = 0; i < 8 && toCheck[i] <= K-2; i++){
        ulli x = modexp(toCheck[i]%K, d, K);
        if(x == 1 || x == K-1) continue;
        bool flag = true;
        for(ulli j = 0; j < r; j++){
            x = (x * x) % K;
            if(x == K-1){
                flag = false;
                break;
            }
        }
        if(flag) return false;
    }
    return true;
}

ulli findFactor(ulli N){ //Pollard Rho
    //cout << "Finding factor of " << toStr(N) << endl;
    if(N == 1 || isPrime(N)) return N;
    if(!(N % 2)) return 2;
    ulli a, b, res = 1;
    bool flag = false;
    while(true){
        a = (Rand()%(N-2)) + 2;
        //cout << "a = " << toStr(a) << endl;
        b = a;
        A = Rand() + 1;
        do{
            b = f(f(b));
            a = f(a);
            res = gcd(N, max(a, b) - min(a, b));
            if(res > 1){
                if(res == N) break; //new set of vals
                return res;
                flag = true;
            }
        } while(a != b);
    }
}

void factorize(ulli N){
    //cout << "Factorizing " << toStr(N) << endl;
    if(N == 1) return;
    if(isPrime(N)){
        if(ps.count(N)){
            ps[N]++;
        } else {
            ps.insert(pair<ulli, ulli>(N, 1));
        }
        //prullif(" %llu", N);
        return;
    }
    //cout << toStr(N) << " is composite " << endl;
    ulli res = findFactor(N);
    //cout << "Found factor: " << toStr(res) << endl;
    factorize(res);
    factorize(N/res);
}

string s;



signed main(){
    cin >> T;
    while(T--){
        cin >> s;
        N = toULLI(s);
        ps.clear();
        //cout << "isPrime(" << N << ") = " << isPrime(N) << endl;
        factorize(N);
        //prullif("%llu =", N);
        cout << toStr(N) << " = ";
        for(auto i = ps.begin(); i != ps.end(); i++){
            if(i != ps.begin()){
                cout << " *";
            }
            cout << " " << toStr(i->first);
            if(i->second > 1){
                cout << "^" << toStr(i->second);
            }
        }
        cout << endl;
        //prullif("\n");
    }
}
