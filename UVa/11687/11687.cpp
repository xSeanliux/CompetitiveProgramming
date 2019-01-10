#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    while(cin >> s){
        if(s == "END") return 0;
        int l = s.length();
        string last = "";
        int ite = 0;
        while(last != s){
            last = s;
            s = to_string(s.length());
            //cout << s << endl;
            ite++;
        }
        cout << ite << endl;
    }
}
