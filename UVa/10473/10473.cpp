#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

string s;

string intToHex(string N){
    int K = stoi(N);
    string d = "0123456789ABCDEF";
    string res = "";
    while(K > 0){
        res = d[ K % 16 ] + res;
        K /= 16;
    }
    return "0x"+ res;
}

string hexToInt(string N){
    string K = N.substr(2);
    int ans = 0, l = K.length();
    for(int i = 0; i < l; i++){
        int d;
        if(K[i] == 'A'){
            d = 10;
        } else if(K[i] == 'B'){
            d = 11;
        } else if(K[i] == 'C'){
            d = 12;
        } else if(K[i] == 'D'){
            d = 13;
        } else if(K[i] == 'E'){
            d = 14;
        } else if(K[i] == 'F'){
            d = 15;
        } else{
            d = K[i] - '0';
        }
        ans += d * pow(16, l-i-1);
    }
    return to_string(ans);
}

int main(){
    while(cin >> s){
        if(s[0] == '-') return 0;
        if(s[1] == 'x'){
            cout <<  hexToInt(s) << endl;
        } else {
            cout <<  intToHex(s) << endl;
        }
    }
}
