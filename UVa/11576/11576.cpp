#include <iostream>
#include <string.h>
using namespace std;

int T, n, k, ans;
string s, newS;

int match(string a, string b){
    for(int i = 0; i < a.length(); i++){
        if(a.substr(i, a.length()) == b.substr(0, a.length() - i)) return i;
    }
    return a.length();
}

int main(){
    cin >> T;
    while(T--){
        cin >> k >> n;
        ans = k;
        cin >> s;
        for(int i = 1; i < k; i++){
            cin >> newS;
            ans += match(s, newS);
            swap(s, newS);
        }
        cout << ans << endl;
    }
}
