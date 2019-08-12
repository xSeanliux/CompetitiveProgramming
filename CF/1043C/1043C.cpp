#include <iostream>
#include <string.h>
using namespace std;

bool d[1003];
string s;
int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        d[i] = 0;
    }
    for(int i = 1; i < s.length(); i++){
        if(s[i] == 'a'){
            d[i] = !d[i];
            d[i-1] = !d[i-1];
        }
    }
    cout << d[0];
    for(int i = 1; i < s.length(); i++){
        cout << " " << d[i];
    }
}
