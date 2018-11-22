#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string s;


int main(){
    while(cin >> s){
        string newS = s;
        reverse(newS.begin(), newS.end());
        newS += '-' + s;
        //cout << newS << endl;
        int l = newS.length();
        int fail[l];
        fail[0] = -1;
        for(int i = 1; i < l; i++){
            int q = fail[i-1];
            while(q > 0 && newS[q + 1] != newS[i]){
                q = fail[q];
            }
            if(newS[q + 1] == newS[i]) q++;
            fail[i] = q;
            //cout << fail[i] << " ";
        }
        //cout << fail[l-1] << endl;
        string revS = s;
        reverse(revS.begin(), revS.end());
        //cout << s << endl;
        //cout << endl;
        int l2 = revS.length();
        //cout << l2 - fail[l-1] << endl;
        string addOn = revS.substr(fail[l-1] + 1, l2);
        cout << s + addOn << endl;
    }
}
