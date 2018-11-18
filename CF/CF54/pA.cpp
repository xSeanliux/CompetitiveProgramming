#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n; string s;
int main(){
    cin >> n >> s;
    string ans;
    for(int i = 0 ; i < n-1; i++){
        if(s[i] > s[i+1]){ //remove ith char
            ans += s.substr(0, i);
            ans += s.substr(i+1, n);
            break;
        } else if(i == n-2){ //remove last char
            ans = s.substr(0, n-1);
        }
    }
    cout << ans << endl;
}
