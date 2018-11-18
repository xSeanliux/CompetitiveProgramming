#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    while(getline(cin , s)){
        if(s == "DONE") return 0;
        int l =  s.length();
        string nS = "";
        int nL = 0;
        for(int i = 0 ; i < l; i++){
            if(('a' <= s[i] && 'z' >= s[i])){
                nS += s[i];
                nL++;
            } else if (('A' <= s[i] && 'Z' >= s[i])) {
                nS += s[i] - 'A' + 'a';
                nL++;
            }
        }
        bool isGood = true;
        if(nL % 2){ //odd
            int k = (nL - 1)/2;
            for(int i = 0; i < k; i++){
                if(nS[i] != nS[nL - i - 1]) isGood = false;
            }
        } else { //even
            int k = nL/2;
            for(int i = 0; i < k; i++){
                if(nS[i] != nS[nL - i - 1]) isGood = false;
            }
        }
        if(isGood){
            printf("You won't be eaten!\n");
        } else {
            printf("Uh oh..\n");
        }
    }
}
