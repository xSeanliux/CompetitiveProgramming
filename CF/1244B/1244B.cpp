#include <iostream>
#include <string.h>
using namespace std;

int t, n;
string s;

int main(){
    cin >> t;
    while(t--){
        cin >> n >> s;
        int ans = n;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                ans = max(ans, 2 * max(i + 1, n - i));
            }
        }
        cout << ans << endl;
    }
}
