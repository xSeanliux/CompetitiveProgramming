#include <iostream>
#include <string.h>
#define WIN "Bicarp"
#define LOSE "Monocarp"
using namespace std;

string s;
int lS = 0, rS = 0, add = 0, sub = 0, l;

int main(){
    cin >> l;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(i < s.length() / 2){
            if(s[i] == '?') add++;
            else lS += s[i] - '0';
        } else {
            if(s[i] == '?') sub++;
            else rS += s[i] - '0';
        }
    }
    int delta = lS - rS;
    if(delta < 0){
        swap(add, sub);
        delta = -delta;
    }
    //now add: increases diff, sub decreases diff (delta).
    if(add > sub){
        cout << LOSE << endl;
    } else {
        sub -= add;
        int myturn = sub/2, histurn = sub - myturn;
        //cout << "Myturn = " << myturn << ", histurn = " << histurn << endl;
        if(9 * histurn > delta || myturn * 9 < delta){
            cout << LOSE << endl;
        } else {
            cout << WIN << endl;
        }
    }
}
