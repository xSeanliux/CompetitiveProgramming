#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

bool isvalid(string s){
    stack<char> stk;
    for(char c : s){
        if(c == '('){
            stk.push(c);
        } else {
            if(stk.empty()) return false;
            stk.pop();
        }
    }
    return stk.empty();
}

int n;
string s;

int main(){
    cin >> n >> s;
    if(isvalid(s)){
        cout << "Yes" << endl;
        return 0;
    }
    stack<char> stk;
    string newstr = "";
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            stk.push(s[i]);
        } else {
            if(stk.empty()){
                for(int j = 0; j < i; j++){
                    newstr += s[j];
                }
                for(int j = i + 1; j < n; j++){
                    newstr += s[j];
                }
                newstr += s[i];
                if(isvalid(newstr)){
                    cout << "Yes" << endl;
                    return 0;
                } else {
                    cout << "No" << endl;
                    return 0;
                }
            } else {
                stk.pop();
            }

        }
    }
    if(stk.empty()){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
