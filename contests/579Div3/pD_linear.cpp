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

int getval(int l, int r){
    int res = 0;
    if(l >= 0) res += premat[l];
    if(r < s.length()) res += sufmat[r];
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    init();

    int l = -1, r = 0, maxlen = 0; //len = r - l - 1
    while(l < (int)s.length()){
        if(getval(l, r) >= t.length() && r < s.length()) r++;
        else l++;
        if(getval(l, r) >= t.length())
            maxlen = max(maxlen, r - l - 1);
        //cout << "l, r= " << l << ", " << r << endl;
    }
    cout << maxlen << endl;
}

