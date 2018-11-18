#include <iostream>
#include <string.h>
using namespace std;

string s, currentS;

bool isGood(string s){
    int oneCounter = 0;
    int l = s.length();
    for(int i = 0 ; i < l-1; i++){
        oneCounter += s[i] - '0';
    }
    if(!(oneCounter % 17)) return true;
    return false;
}

int main(){
    s = "";
    while(cin >> currentS){
        s += currentS;
        if(currentS[currentS.length()-1] == '#'){
            if(isGood(s) || s == "0#"){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            s = "";
        }

    }
}
