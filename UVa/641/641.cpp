#include <iostream>
#include <string.h>
using namespace std;

int k;
string s;

int getNum(char c){
    if(c == '_') return 0;
    if(c == '.') return 27;
    return (c - 'a' + 1);
}

char getChar(int x){
    if(x == 0) return '_';
    if(x == 27) return '.';
    return (x - 1 + 'a');
}

int main(){
    while(cin >> k >> s){
        for(int i = 0; i < s.length(); i++){
            cout <<
        }
    }
}
