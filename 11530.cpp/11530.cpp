#include <iostream>
#include <string.h>
using namespace std;

int N, ans, c;
string s, _t;

int get(char c){
    if(c == ' ') return 1;
    int code = c - 'a';
    if(code < 15){
        if(code % 3 == 0) return 1;
        else if(code % 3 == 1) return 2;
        else return 3;
    } else {
        if(c == 'p' || c == 't' || c == 'w'){
            return 1;
        } else if(c == 'q' || c == 'u' || c == 'x'){
            return 2;
        } else if(c == 'r' || c == 'v' || c == 'y'){
            return 3;
        } else {
            return 4;
        }
    }

}

int main(){
    cin >> c;
    getline(cin, _t);
    for(int k = 1; k <= c; k++){
        getline(cin, s);
        int l = s.length();
        ans = 0;
        for(int i = 0; i < l; i++){
            //cout << s[i] << ": " << get(s[i]) << endl;
            ans += get(s[i]);
        }
        printf("Case #%d: %d\n", k, ans);
    }


}
