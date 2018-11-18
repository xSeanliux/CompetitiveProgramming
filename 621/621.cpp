#include <iostream>
#include <string.h>
using namespace std;

int c;
string s;

int main(){
    cin >> c;
    for(int ia = 0; ia < c; ia++){
        cin >> s;
        if(s == "1" || s == "4" || s == "78"){
            cout << "+" << endl;
        } else {
            int l = s.length();
            if(s[l-1] == '5' && s[l-2] == '3'){
                cout << "-" << endl;
            } else if(s[0] == '9' && s[l-1] == '4'){
                cout << "*" << endl;
            } else if(s.substr(0, 3) == "190"){
                cout << "?" << endl;
            }
        }
    }
}
