#include <iostream>
#include <string.h>
using namespace std;

string com, s;

int main(){
    while(cin >> com >> s){
        int l = com.length();
        cout << "L: " << l << endl;
        for(int i = 0; i < l-1; i += 4){
            cout << "Portion: " << com.substr(i, 4) << endl;
            char c1 = com[i], c2 = com[i + 1];
            int ind = (com[i+2] - '0')*10 + (com[i+3]- '0');
            if(c1 == 'I'){
                s = s.substr(0, ind - 1) + c2 + s.substr(ind-1);
            } else if(c1 == 'C'){
                s[ind-1] = c2;
            } else if(c1 == 'D'){
                s = s.substr(0, ind - 1) + s.substr(ind);
            }
            cout << s << endl;
        }
        cout << s << endl;
    }
}

