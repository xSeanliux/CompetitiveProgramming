#include <iostream>
using namespace std;

string s;
int t;

bool isV(char c){
    return (c == 'A') || (c == 'E') || (c == 'I') || (c == 'O') || (c == 'U');
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> s;
        int ans = 1000000;
        for(char c = 'A'; c <= 'Z'; c++){
            int cur = 0; 
            for(char ch : s){
                if(ch == c) continue;
                if(isV(ch) ^ isV(c)){
                    cur++;
                } else cur += 2;
            }
            ans = min(cur, ans);
        }
        cout << "Case #" << ++t << ": " << ans << endl;
    }
}
