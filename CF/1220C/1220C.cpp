#include <iostream>
#include <string.h>
using namespace std;

string s;
char minChar[(int)5e5 + 10];


int main(){
    cin >> s;
    minChar[0] = s[0];
    for(int i = 1; i < s.length(); i++){
        minChar[i] = min(minChar[i - 1], s[i]);
    }
    for(int i = 0; i < s.length(); i++){
        if(minChar[i] < s[i]){
            cout << "Ann" << endl;
        } else {
            cout << "Mike" << endl;
        }
    }
}
