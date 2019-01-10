#include <iostream>
#include <string.h>
using namespace std;

int c, chars, lines;
string s, _t;
struct Letter{
    char c;
    int value;
};

Letter vals[100 + 5];

int returnVal(char C){
    for(int i = 0; i < chars; i++){
        if(vals[i].c == C) return vals[i].value;
    }
    return 0;
}

int main(){
    cin >> c;
    for(int ia = 0; ia < c; ia++){
        cin >> chars;
        int total = 0;
        for(int i = 0; i < chars; i++){
            cin >> vals[i].c >> vals[i].value;
        }
        cin >> lines;
        getline(cin, _t);
        for(int k = 0; k < lines; k++){
            getline(cin, s);
            int l = s.length();
            for(int i = 0; i < l; i++){
                total += returnVal(s[i]);
            }
        }
        printf("%.2f$\n", (total+0.0)/100);
    }
}
