#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

string s;

int maxLen;

int main(){
    while(getline(cin, s)){
        int l = s.length();
        int len = 0;
        maxLen = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == ' ' && i != l-1){
                len++;
            } else {
                if(i == l-1 && s[i] == ' '){
                    len++;
                }
                if(maxLen < len){
                    maxLen = len;
                }
                len = 0;
            }
        }
        int ans;
        if(maxLen != 0){
            ans = ceil(log2(maxLen));
        } else {
            ans = 0;
        }

        printf("%d\n", ans);
    }
}
