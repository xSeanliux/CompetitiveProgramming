#include<iostream>
#include<string.h>
#define int unsigned long long int
using namespace std;

string A = "What are you doing while sending \"", B = "\"? Are you busy? Will you send \"", C = "\"?", D = "What are you doing at the end of the world? Are you busy? Will you save us?";
int lens[100], q, lenA, lenB, lenC, lenD, n, k;

char getChar(int n, int k){
    if(k >= lens[n]) return '.';
    if(!n) return D[k];
    int currentreg = 0;
    if(k < lenA) return A[k];
    k -= lenA;
    if(k < lens[n - 1]) return getChar(n - 1, k);
    k -= lens[n - 1];
    if(k < lenB) return B[k];
    k -= lenB;
    if(k < lens[n - 1]) return getChar(n - 1, k);
    k -= lens[n - 1];
    return C[k];
}

void solve(){
    cin >> n >> k;
    k--;
    if(n > 53){ //padded with A's
        if(k < n * lenA){
            cout << A[k % lenA];
            return;
        }
        for(int j = 0; j <= 53; j++){
            if(lens[j] + (n - j) * lenA > k){ //do.
                k -= (n - j) * lenA;
                cout << getChar(j, k);
                return;
            }
        }

    } else {
        if(k >= lens[n]){
            cout << ".";
            return;
        } else {
            cout << getChar(n, k);
        }
    }
}



signed main(){
    lens[0] = D.length();
    int clen;
    lenA = A.length(), lenB = B.length(), lenC = C.length(), lenD = D.length(), clen = lenD;
    for(int i = 1; i <= 54; i++){
        clen = lenA + lenB + lenC + 2 * clen;
        lens[i] = clen;
    }
    cin >> q;
    while(q--){
        solve();
    }
}
