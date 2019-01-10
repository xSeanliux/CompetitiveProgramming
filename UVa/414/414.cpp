#include <iostream>
#include <string.h>
using namespace std;

string s, _t;

int h, sB, minB, len = 25, blanks;

int main(){
    while(cin >> h){
        if(!h) return 0;
        sB = 0;
        minB = -1;
        getline(cin, _t);
        for(int ia = 0 ; ia < h ; ia++){
            getline(cin, s);
            blanks = 0;
            for(int i = 0 ; i < len; i++){
                if(s[i] == ' '){
                    blanks++;
                }
            }
            sB += blanks;
            if(minB > blanks || minB == -1){
                minB = blanks;
            }
        }
        int ans = sB - h*minB;
        printf("%d\n", ans);
    }
}
