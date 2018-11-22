#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
string s;
char getMirror(char c){
    if(c == 'A'){
        return c;
    } else if(c == 'H'){
        return c;
    } else if(c == 'I'){
        return c;
    } else if(c == 'M'){
        return c;
    } else if(c == 'T'){
        return c;
    } else if(c == 'U'){
        return c;
    } else if(c == 'V'){
        return c;
    } else if(c == 'W'){
        return c;
    } else if(c == 'X'){
        return c;
    } else if(c == 'Y'){
        return c;
    } else if(c == '1'){
        return c;
    } else if(c == '8'){
        return c;
    } else if(c == 'E'){
        return '3';
    } else if(c == '3'){
        return 'E';
    } else if(c == 'J'){
        return 'L';
    } else if(c == 'L'){
        return 'J';
    } else if(c == 'S'){
        return '2';
    } else if(c == '2'){
        return 'S';
    } else if(c == 'Z'){
        return '5';
    } else if(c == '5'){
        return 'Z';
    } else if(c == 'O'){
        return 'O';
    } else if(c == ' '){
        return c;
    } else {
        return '@'; //just a char that isn't in this.
    }
}


bool isPalindrome(string s){
    string _s = s;
    reverse(s.begin(), s.end());
    return (_s == s);
}

bool isMirror(string s){
    string res = "";
    int l = s.length();
    for(int i = 0; i < l; i++){
        res += getMirror(s[i]);
    }
    reverse(s.begin(), s.end());
    return s == res;
}


int main(){
    while(cin >> s){
        bool isP = isPalindrome(s);
        bool isM = isMirror(s);
        cout << s << " -- ";
        if(isP && isM){
            cout << "is a mirrored palindrome." << endl;
        } else if(!isP && isM){
            cout << "is a mirrored string." << endl;
        } else if(!isM && isP){
            cout << "is a regular palindrome." << endl;
        } else {
            cout << "is not a palindrome." << endl;
        }
        cout << endl;
    }
}
