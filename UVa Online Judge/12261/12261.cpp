#include <iostream>
#include <string.h>
using namespace std;

string s;
int C;

int main(){
    cin >> C;
    while(C--){
        cin >> s;
        char currentChar = 'A';
        int l = s.length(), ans = 0;
        for(int i = 0 ; i < l; i++){
            ans += min(s[i] - currentChar, (26 - (s[i] - currentChar)) % 26 );
            currentChar = s[i];
        }
        cout << ans + l-1 << endl;
    }
}
