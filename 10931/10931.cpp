#include <iostream>
#include <string.h>
using namespace std;

string s;

string returnBinary(string s){
    int K = stoi(s);
    string res = "";
    while(K > 0){
        int r = K % 2;
        res = to_string(r) + res;
        K -= r;
        K /= 2;
    }
    return res;
}

int main(){
    while(cin >> s){
        if(!stoi(s)) return 0;
        int p = 0;
        string res = returnBinary(s);
        int l = res.length();
        for(int i = 0 ; i < l; i++){
            p += res[i] - '0';
        }
        cout << "The parity of " << res << " is " << p << " (mod 2)." << endl;
    }
}
