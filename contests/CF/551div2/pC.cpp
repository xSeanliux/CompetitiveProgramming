#include <iostream>
#include <string.h>
#include <math.h>
#include <stack>
using namespace std;

int l, quesC, lC, rC;
string s;

int main(){
    cin >> l >> s;
    if(s.length() % 2 || s[0] == ')' || s[l-1] == '('){
        cout << ":(" << endl;
        return 0;
    }
    s[0] = '('; s[l-1] = ')';
    quesC = lC = rC = 0;
    for(int i = 1; i < l-1; i++){
        if(s[i] == '(') lC++;
        else if(s[i] == ')') rC++;
        else quesC++;
    }
    if(quesC < abs(lC - rC) || (abs(lC - rC) - quesC) % 2){
        cout << ":(" << endl;
        return 0;
    }
    int needL = (quesC - abs(lC - rC)) / 2, needR = (quesC - abs(lC - rC)) / 2;
    if(lC > rC){
        needR += abs(lC - rC);
    } else {
        needL += abs(lC - rC);
    }
    for(int i = 1; i < l - 1; i++){
        if(s[i] == '?'){
            if(needL){
                s[i] = '(';
                needL--;
            } else {
                s[i] = ')';
                needR--;
            }
        }
    }
    //cout << s << endl;
    stack<char> stk;
    for(int i = 1; i < l - 1; i++){
        if(s[i] == '('){
            stk.push('(');
        } else {
            if(stk.empty()){
                cout << ":(" << endl;
                return 0;
            }
            stk.pop();
        }
    }
    if(stk.size()){
        cout << ":(" << endl;
        return 0;
    }
    cout << s << endl;
}
