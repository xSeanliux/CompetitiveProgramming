#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int T, bc, c = 0;
string s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> s;
        int l = s.length();
        bc = 0;
        for(int i = 1; i < l; i++) bc += (s[i] == 'B');
        cout << "Case #" << ++c << ": ";
        if(bc < (l - 1) && bc >= l/2) cout << "Y" << '\n';
        else cout << "N" << '\n';
    }
}
