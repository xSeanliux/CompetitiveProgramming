#include <iostream>
#include <string.h>
using namespace std;
string s;

char getNum(char c){
    if(c <= 'C'){
        return '2';
    } else if(c <= 'F'){
        return '3';
    } else if(c <= 'I'){
        return '4';
    } else if(c <= 'L'){
        return '5';
    } else if(c <= 'O'){
        return '6';
    } else if(c <= 'S'){
        return '7';
    } else if(c <= 'V'){
        return '8';
    } else if(c <= 'Z'){
        return '9';
    }
}

int main(){
    while(cin >> s){
        int l = s.length();
        for(int i = 0; i < l; i++){
            if(s[i] <= 'Z' && s[i] >= 'A'){
                printf("%c", getNum(s[i]));
            } else {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
}
