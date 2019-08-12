
#include <iostream>
using namespace std;

string s, t;

int main(){
    cin >> s >> t;
    int ls = s.length(), lt = t.length();
    int fail[ls + 10];
    fail[0] = -1;
    for(int i = 1; i < ls; i++){
        int q = fail[i - 1];
        while(q > 0 && s[q + 1] != s[i]) q = fail[q];
        if(s[q + 1] == s[i]) q++;
        fail[i] = q;
    }
    int matched = 0, currentInd = 0;
    for(int i = 0; i < ls; i++) fail[i]++;
    int ans[lt + 5], ind = 0;
    while(currentInd < lt){
        if(s[matched] != t[currentInd]){
            if(!matched) currentInd++;
            else {
                matched = fail[matched - 1];
            }
        } else {
            matched++;
            currentInd++;
            if(matched == ls){
                ans[ind++] = currentInd - matched;
                matched = fail[matched - 1];
            }
        }

    }
    if(!ind) cout << endl;
    for(int i = 0; i < ind; i++) cout << ans[i] << " \n"[i == ind-1];
}

/*
#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

string s, t;
const int maxN = 5e5, b = 10, p = 1e9 + 7;

int exp(int b, int e){
    if(e == 1) return b;
    int res = exp(b, e/2);
    res = res * res % p;
    if(e % 2) res = res * e % p;
    return res;
}

signed main(){
    cin >> s >> t;
    //get hash of t
    int hashT[t.length()], ans[t.length()], ind = 0;

    int inv = exp(b, s.length() - 2);
    int hashVals[t.length() + 5], hashS = 0;
    for(int i = 0; i < s.length(); i++){
        hashS = (hashS * b + p) % p + (s[i] - 'a' + 1);
    }
    hashVals[0] = 0;
    for(int i = 1; i <= t.length(); i++){
        hashVals[i] = (hashVals[i-1]*b + (t[i] - 'a' + 1)) % p;
    }
    for(int i = s.length(); i <= t.length(); i++){
        //cout << "Roll: " << ((hashVals[i] - hashVals[i - s.length()] * exp(b, s.length())) * exp(inv, s.length())) << endl;
        if(hashS == ((hashVals[i] - hashVals[i - s.length()] * exp(b, s.length())) * exp(inv, s.length()))) ans[ind++] = i - s.length();
    }
    if(!ind) cout << endl;
    for(int i = 0; i < ind; i++) cout << ans[i] << " \n"[i == ind - 1];
}
*/
