#include <iostream>
#include <string.h>
#include <deque>
using namespace std;

const int maxN = 2e5;

string s, t;

int premat[maxN + 10], sufmat[maxN + 10];

void init(){
    int cur = 0;
    for(int i = 0; i < s.length(); i++){
        if(i){
            premat[i] = premat[i - 1];
        } else {
            premat[i] = 0;
        }
        if(s[i] == t[cur]){
            premat[i]++;
            cur++;
        }
    }
    cur = t.length() - 1;
    for(int i = s.length() - 1; i >= 0; i--){
        if(i == s.length() - 1){
            sufmat[i] = 0;
        } else {
            sufmat[i] = sufmat[i + 1];
        }
        if(s[i] == t[cur]){
            sufmat[i]++;
            cur--;
        }
    }
}


inline bool issubseq(int l, int r){ //[0, l] & [r, s.length() - 1],
    int res = 0;
    if(l >= 0) res += premat[l];
    if(r < s.length()) res += sufmat[r];
    return (res >= t.length());
}



bool check(int l){ //string len l;
    //cout << "Checking " << l << endl;
    for(int i = 0; i <= s.length() - l; i++){
        //cout << "i = " << i << endl;
        if(issubseq(i - 1, i + l)) return true;
    }
    //cout << "NO: l = " << l << endl;
    return false;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    init();

    int l = 0, r = s.length() - t.length() + 1, m = (l + r) / 2 ;
    while(l + 1 < r){
        if(check(m)){
            l = m;
        } else {
            r = m;
        }
        m = (l + r) / 2;
    }

    cout << l << endl;
}
