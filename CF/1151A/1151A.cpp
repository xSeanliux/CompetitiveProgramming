#include <iostream>
#include <string.h>
using namespace std;

inline int dist(char i, char j){
    int d = max(i - j, j - i);
    return min(d, 26 - d);
}

int main(){
    string s;
    int l;
    cin >> l >> s;
    int ans = 109129;
    for(int i = 0; i < l - 3; i++){
        ans = min(ans, dist(s[i], 'A') + dist(s[i + 1], 'C') + dist(s[i + 2], 'T') + dist(s[i + 3], 'G'));
    }
    cout << ans << endl;
}
