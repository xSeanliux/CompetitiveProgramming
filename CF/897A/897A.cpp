#include <iostream>
#include <string.h>
using namespace std;

int n, m, l, r;
string s;
char c1, c2;

int main(){
    cin >> n >> m;
    cin >> s;
    while(m--){
        cin >> l >> r >> c1 >> c2;
        l--;
        for(int i = l; i < r; i++){
            if(s[i] == c1) s[i] = c2;
        }
    }
    cout << s << endl;
}
