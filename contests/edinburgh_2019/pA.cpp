#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int ans, N;
string s, rs;

int main(){
    cin >> N;
    while(N--){
        cin >> s;
        rs = s;
        reverse(s.begin(), s.end());
        ans += (rs == s);
    }
    cout << ans << endl;
}
