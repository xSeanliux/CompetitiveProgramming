#include <iostream>
#include <string.h>
using namespace std;
bool hasHole(char c){
    if(c == 'a' || c == 'b' || c == 'd' || c == 'e' || c == 'o' || c == 'p' || c == 'q')
        return true;
    return false;
}
string genString(int len, int holes){
    if(len < holes || holes < 0 || len < 0) return "-";
    else{
        string s = "";
        while(holes){
            s += 'a';
            len--;
            holes--;
        }
        while(len){
            s += 'c';
            len--;
        }
        return s;
    }
}

string succ(string s){
    int l = s.length();
    int holes = 0;
    bool canDo = false;
    for(int i = l-1; i >= 0 && !canDo; i--){
        char c = s[i], nextChar = c+1;
        while(nextChar <= 'z'){
            if(nextChar == 'g') nextChar++;
            string newS = genString(l - i - 1, holes + hasHole(c) - hasHole(nextChar));
            if(newS != "-"){
                return s.substr(0, i) + nextChar + newS;
                canDo = true;
                break;
            }
            nextChar = nextChar+1;
        }
        holes += hasHole(c);
    }
    if(!canDo) return "-1";
}
int T, N, K;
string s;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> K >> s;
        cout << succ(s) << endl;
    }
}
