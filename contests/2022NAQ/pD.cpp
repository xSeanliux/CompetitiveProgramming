#include <iostream>
#include <string.h>
#include <cassert>
#include <vector>
#include <map>
#define double long double
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 326;
map<string, int> id = map<string, id>();
vector<int> primes = {(int)1e7 + 9, (int)1e9 + 7, 103, 99991, 99989, 99971, 99961, 99929, 99923, 99907, 99901, 99881, 99877};
int arr[maxN][maxN], _arr[maxN][maxN];
int N, M;
vector<vector<string>> tokens;

inline void addId(string &s) {
   if(!id.count(s)) id[s] = id.size(); 
}

inline int mpow(int b, int e, int M) {
    int r = 1;
    for(int i = 0; i < 33; i++) {
        if((e >> i) & 1) r = r * b % M;
        b = b * b % M;
    }
    return r;
}

inline int inv(int x, int M) {
    return mpow(x, M - 2, M);
}

/*
inline void sieve() {
    int n = 1e5;
    bool isPrime[n];
    fill(isPrime, isPrime + n, true);
    vector<int> primes = vector<int>();
    for(int i = 2; i < n; i++) {
        if(isPrime[i]) primes.push_back(i);
        for(int j = i * i; j < n; j += i) isPrime[j] = false;
    }
    reverse(primes.begin(), primes.end());
    for(int i = 0; i < 10; i++) cout << primes[i] << ", ";
}
*/

inline bool GetRREF(int P) {
    int curCol = 0;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) _arr[i][j] = (P + arr[i][j]) % P;
    for(int i = 0; i < N; i++) {
        int bestRow;
        do {
            bestRow = i;
            for(int j = i; j < N; j++) if(_arr[j][curCol] != 0) bestRow = j;
            if(_arr[bestRow][curCol] == 0) curCol++;
            else break;
        } while(curCol < M);
        if(curCol < M) {
            for(int j = 0; j < M; j++) swap(_arr[bestRow][j], _arr[i][j]);
            for(int j = 0; j < N; j++) {
                if(j == i) continue;
                int fact = _arr[j][curCol] * inv(_arr[i][curCol], P) % P;
                for(int k = 0; k < M; k++) {
                    _arr[j][k] = (_arr[j][k] - fact * _arr[i][k] % P + P) % P;
                }
            }
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            printf("%lld ", _arr[i][j]);
        }
        printf("\n");
    }
    */

    for(int i = 0; i < N; i++) {
        int nz = 0;
        for(int j = 0; j < M; j++) {
            nz += (_arr[i][j] != 0);
        }
        if(nz == 1) return false;
    }
    return true;
}

signed main() {
    ericxiao
    cin >> N;
    string s;
    getline(cin, s);
    while(N--) {
        getline(cin, s); 
        vector<string> _tokens = vector<string>();
        string cur = "";
        for(char c : s) {
            if(c == ' ') {
                _tokens.push_back(cur);
                cur = "";
            } else cur += c;
        }
        _tokens.push_back(cur);
        for(string tok : _tokens) {
            if(tok != "*" && tok != "/" && tok != "=" && tok != "1") addId(tok);
        }
        tokens.push_back(_tokens);
    }
    N = 0;
    M = id.size() + 1;
    for(auto v : tokens) {
        bool lhs = true, mult = true;
        for(string s : v) {
            if(s == "*") mult = true;
            else if(s == "/") mult = false;
            else if(s == "=") {
                lhs = false;
                mult = true;
            }
            else if(s != "1") {
                if(lhs ^ mult) arr[N][id[s]]--;
                else arr[N][id[s]]++;
            }
        }
        N++;
    }
    assert(M < maxN);
    assert(N < maxN);
    for(int p : primes) {
        if(GetRREF(p)) {
            cout << "valid" << endl;
            return 0;
        }
    }
    cout << "invalid" << endl;
}
