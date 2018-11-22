#include <iostream>
#include <string.h>
using namespace std;

string str;
string words[50 + 5];
char start;
int head;


char toLower(char s){
    if('a' <= s && s <= 'z'){
        return s;
    } else {
        return s - 'A' + 'a';
    }
}

string low(string s){
    string res = "";
    int l = s.length();
    for(int i = 0 ; i < l; i++){
        res += toLower(s[i]);
    }
    return res;
}

int main(){
    while(getline(cin, str)){
        if(str == "*") return 0;
        int l = str.length();
        string cW = "";
        head = 0;
        for(int i = 0 ; i < l; i++){
            if(str[i] == ' '){
                words[head] = low(cW);
                head++;
                cW = "";
            } else {
                cW += str[i];
                if(i == l-1){
                    words[head] = low(cW);
                    head++;
                    cW = "";
                }
            }
        }
        start = words[0][0];
        bool flag = true;
        for(int i = 0 ; i < head; i++){
            //cout << words[i][0] << endl;
            if(!(flag && words[i][0] == start)){
                flag = false;
            }
        }
        if(flag){
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
}
