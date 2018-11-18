#include <iostream>
#include <string.h>

using namespace std;

string s;
char charArr[100 + 5][100 + 5];
int sentences, l, maxL = 0;

int main(){
    sentences = 0;
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 102; j++){
            charArr[i][j] = (char)230; //please don't type the greek letter mu lol
        }
    }
    while(getline(cin, s)){
        l = s.length();
        for(int i = 0; i < l; i++){
            charArr[sentences][i] = s[i];
        }
        sentences++;
        if(maxL < l) maxL = l;

    }
    for(int i = 0; i < maxL; i++){
            for(int j = sentences - 1; j >= 0; j--){
                //printf charArr[j][i]
                if(charArr[j][i] == (char)230){
                    printf(" ");
                } else {
                    printf("%c", charArr[j][i]);
                }
            }
       printf("\n");
        }


}
