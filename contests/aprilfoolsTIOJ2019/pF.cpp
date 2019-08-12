#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    cin >> s;
    for(int i = 0; i < s.length(); i++) cout << ((s[i] == 't' || s[i] == 'd' || s[i] == 'g') ? 1 : 0);
}
