#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long int
using namespace std;

int q, n;

string ternary;

string toTern(int x){
    string res = "";
    while(x){
        res = (char)(x % 3 + '0') + res;
        x /= 3;
    }
    return res;
}

int toInt(string s){ //binary to dec
    int res = 0;
    for(char c : s){
        res *= 2;
        res += (c - '0');
    }
    return res;
}

string toBinary(int x){
    string res = "";
    while(x){
        res = (char)(x % 2 + '0') + res;
        x /= 2;
    }
    return res;
}

int terToDec(string s){
    int res = 0;
    for(char c : s){
        res *= 3;
        res += (c - '0');
    }
    return res;
}

signed main(){
    cin >> q;
    while(q--){
        cin >> n;
        ternary = toTern(n);
        int tind;
        for(tind = 0; tind < ternary.length(); tind++){
            if(ternary[tind] == '2') break;
        }
        if(tind == ternary.length()){
            cout << n << endl;
            continue;
        }
        string pre = toBinary(toInt(ternary.substr(0, tind))  + 1);
        for(int i = tind; i < ternary.length(); i++) pre += '0';
        cout << terToDec(pre) << endl;
    }
}
