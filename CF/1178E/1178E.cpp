#include <iostream>
#include <string.h>
using namespace std;

string s, ans = "";
int N;

int main(){
    cin >> s;
    N = s.length();
    int vals[3];
    char c = '$';
    for(int i = 0; i < N/4; i++){ //2i, 2i + 1
        vals[0] = vals[1] = vals[2] = 0;
        vals[ s[2 * i              ] - 'a']++;
        vals[ s[2 * i + 1          ] - 'a']++;
        vals[ s[N - 1 - (2 * i)    ] - 'a']++;
        vals[ s[N - 1 - (2 * i + 1)] - 'a']++;
        for(int j = 0; j < 3; j++){
            if(vals[j] > 1){
                ans += j + 'a';
                break;
            }
        }
    }
    if(N % 4) c = s[N/2];
    for(int i = 0; i < ans.length(); i++) cout << ans[i];
    if(c != '$') cout << c;
    for(int i = ans.length() - 1; i >= 0; i--) cout << ans[i];
    cout << endl;
}
