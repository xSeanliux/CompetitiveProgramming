#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    while(cin >> s){
        if(s == ".")
            return 0;
        int l = s.length();
        int fail[l];
        fail[0] = -1;
        //cout << "-1 ";
        for(int i = 1; i < l; i++){
            int q = fail[i-1];
            while(s[q + 1] != s[i]){
                if(q == -1) break;
                q = fail[q];
            }
            if(s[q+1] == s[i]) q++;
            fail[i] = q;
            //cout << fail[i] << " ";
        }
        int rep = l - fail[l - 1] - 1;
        if(!(l % rep) && fail[l-1] != -1){
            cout << l/rep << endl;
        } else {
            cout << 1 << endl;
        }
        //cout << endl;
    }
}
