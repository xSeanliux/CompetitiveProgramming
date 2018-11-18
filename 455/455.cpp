#include <iostream>
#include <string.h>
using namespace std;


string s, sub, _t;
int c;

bool isRepeat(string b, string s){
    int lb = b.length();
    int ls = s.length();
    for(int i = 0; i <= lb - ls; i += ls){
        if(b.substr(i, ls) != s) return false;
    }
    return true;
}

int main(){
    cin >> c;
    getline(cin, _t);
    for(int kk = 0; kk < c; kk++){

        getline(cin, _t);
        getline(cin, s);
        int l = s.length();

        if(kk > 0){
            printf("\n");
        }

        //cout << isRepeat("abab", "ab") << endl;
        bool noRepeats = true;
        for(int i = 1; 2 * i <= l ; i++){
            if(l % i == 0){
                sub = s.substr(0, i);
                if(isRepeat(s, sub)){
                    printf("%d\n", i);
                    noRepeats = false;
                    break;
                }
            }
        }
        if(noRepeats) printf("%d\n", l);
    }
}

