#include <iostream>
#include <string.h>
#include <map>
#define lli long long int
using namespace std;

string in, orib, newb, out, s = "0123456789ABCDEF";
map<char, int> vals;

lli getValue(string in, int base){
    lli res = 0;
    for(char c : in){
        res += vals[c];
        res *= base;
    }
    return res / base;
}

string getString(lli value, int base){
    string S = "";
    while(value){
        S = s[value % base] + S;
        value /= base;
    }
    return S;
}

int main(){
    vals.clear();
    for(int i = 0; i < 16; i++) vals.insert({s[i], i});
    while(cin >> in >> orib >> newb){
        out = getString(getValue(in, stoi(orib)), stoi(newb));
        while(out.length() > 1 && out[0] == '0') out = out.substr(1);
        if(out == "") out = "0";
        if(out.length() > 7) puts("  ERROR");
        else {
            for(int i = 0; i < 7- out.length(); i++) cout << " ";
            cout << out << endl;
        }
    }
}
