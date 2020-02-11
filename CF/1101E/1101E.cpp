#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int ch = 0, cw = 0, x, y, n;
char c;

int main(){
    ericxiao;
    cin >> n;
    while(n--){
        cin >> c >> x >> y;
        if(x > y) swap(x, y);
        if(c == '+'){
            ch = max(y, ch);
            cw = max(x, cw);
        } else if(c == '?'){
            cout << ((y >= ch && x >= cw) ? "YES" : "NO") << endl;
        }
    }
}
