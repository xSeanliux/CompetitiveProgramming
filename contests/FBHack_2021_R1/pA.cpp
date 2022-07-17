#include <iostream>
#include <string.h>
using namespace std;

inline void solve(int tc){
    int N;
    string s;
    cin >> N >> s;
    int curHand = 0, ans = 0;
    for(char c : s){
        if(c == 'O'){
            if(curHand == 2) ans++;
            curHand = 1;
        } else if(c == 'X'){
            if(curHand == 1) ans++;
            curHand = 2;
        }
    }
    cout << "Case #" << tc << ": " << ans << endl;
}

int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
}
