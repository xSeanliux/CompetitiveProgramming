#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    cin >> s;
    int l = -1, r = -1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '['){
            l = i;
            break;
        }
    }
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] == ']'){
            r = i;
            break;
        }
    }
    if(l == -1 || r == -1){
        cout << -1 << endl;
        return 0;
    }
    int cl = -1, cr = -1;
    for(int i = l + 1; i < r; i++){
        if(s[i] == ':'){
            cl = i;
            break;
        }
    }
    for(int i = r - 1; i > l; i--){
        if(s[i] == ':'){
            cr = i;
            break;
        }
    }
    if(cl == cr || cl == -1 || cr == -1){
        cout << -1 << endl;
        return 0;
    }
    int vc = 0;
    for(int i = cl + 1; i < cr; i++){
        vc += (s[i] == '|');
    }
    cout << vc +  4 << endl;
}
