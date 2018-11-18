#include <iostream>
#include <string.h>
using namespace std;

int N;
string s, _t;

int main(){
    cin >> N;
    int ia = 0;
    getline(cin, _t);
    while(getline(cin, s)){
        if(s == ""){
            if(ia < N - 1){
                cout << endl;
                ia++;
            } else {
                return 0;
            }
        } else {
            int l = s.length();
            for(int i = 0; i < l; i++){
                if(s[i] == '0'){
                    printf("%c", 'O');
                } else if(s[i] == '1'){
                    printf("%c", 'I');
                } else if(s[i] == '2'){
                    printf("%c", 'Z');
                } else if(s[i] == '3'){
                    printf("%c", 'E');
                } else if(s[i] == '4'){
                    printf("%c", 'A');
                } else if(s[i] == '5'){
                    printf("%c", 'S');
                } else if(s[i] == '6'){
                    printf("%c", 'G');
                } else if(s[i] == '7'){
                    printf("%c", 'T');
                } else if(s[i] == '8'){
                    printf("%c", 'B');
                } else if(s[i] == '9'){
                    printf("%c", 'P');
                } else {
                    printf("%c", s[i]);
                }
            }
            cout << endl;
            }
        }
    }


