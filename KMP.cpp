#include <iostream>
#include <string.h>
using namespace std;

string s1, s2;
int pi[1000];

void fail(string s){
    pi[0] = -1;
    int l = s.length();
    cout << "-1 ";
    int q = -1;
    for(int i = 1; i < l; i++){
        while(s[q+1] != s[i] && q >= 0){
            q = pi[q];
        }
        if(s[q + 1] == s[i]){
            q++;
        }
        pi[i] = q;
        //cout << pi[i] << " ";
    }
}

int main(){
    while(cin >> s1 >> s2){
        fail(s2);
        int l2 = s2.length();
        int l1 = s1.length();
        int q = -1; //number of matched chars
        bool isMatch = false;
        bool hasMatched = false;
        for(int i = 0 ; i < l1; i++){
            cout << "i = " << i << endl;
            while(q >= -1 && s2[q + 1] != s1[i]){
                q = pi[q];
                cout << "q is now "<< q << endl;
            }
            if(s2[q+1] == s1[i]){
                cout << "s2[" << q + 1 << "] = s1[" << i << "]" << endl;
                q++;
            }
            cout << "the value of q is " << q << endl;
            if(q == l2-1){
                cout << "Matched wth shift " << i << endl;
                q = pi[q];
                hasMatched = true;
            }
        }
        if(!hasMatched){
            cout << "No match found" << endl;
        }
    }
}
