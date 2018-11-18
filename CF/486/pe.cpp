#include <iostream>
#include <string.h>
using namespace std;

string s;
int m, c;
int digs[10];
int main(){
    cin >> s;
    for(int i = 0 ; i < 10;i++){
        digs[i] = 0;
    }
    int l = s.length();
    for(int i = 0 ; i < l; i++){
        digs[s[i] - '0']++;
    }
    if(digs[0]){
        string newS;
        for(int i = l-1; i >= 0; i--){
            if(s[i] == '0'){
                for(int j = 0 ; j < l; i++){
                    if(j != i){
                        newS += s[i];
                    }
                    newS += s[i];
                    if(newS[l-2] == 0 || newS[l-2] == 5){
                        m = l-i;
                        cout << 1 << endl;
                        return 0;
                    }
                }

            }
        }
    }
}
