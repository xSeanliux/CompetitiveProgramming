#include <iostream>
#include <string.h>
using namespace std;

string c, word, words[100000];
int head;

bool isP(string s){
    int l = s.length();
    int k = l;
    k -= k % 2;
    k /= 2;
    for(int i = 0 ; i < k; i++){
        if(s[i] != s[l - i - 1]) return false;
    }
    return true;
}



int main(){
    while(cin >> c){
        if(isP(c)) cout << c << endl;
    }
}
