#include <iostream>
#include <string.h>
using namespace std;

string s;
int l;

int main(){
    cin >> s;
    l = s.length();
    int fail[l + 5];
    fail[0] = -1;
    for(int i = 1; i < l; i++){
        int q = fail[i - 1];
        while(q >= 0 && s[q + 1] != s[i]) q = fail[q];
        if(s[q + 1] == s[i]) q++;
        fail[i] = q;
    }
    if(l % (l - fail[l - 1] - 1) == 0){
        cout << l - fail[l - 1] - 1 << endl;
    } else {
        cout << l << endl;
    }
}
