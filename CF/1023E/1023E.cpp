#include <iostream>
#include <string.h>
using namespace std;

int n, x, y;
string ans = "", res;

int main(){
    cin >> n;
    x = y = 1;
    while(n - x - y + 1 > 0){
        if(x < n){
            cout << "? " << x + 1 << " " << y << " " << n << " " << n << endl;
            cout << flush;
            cin >> res;
            if(res == "YES"){
                ans += 'D';
                x++;
            } else if(y < n){
                cout << "? " << x << " " << y + 1 << " " << n << " " << n << endl;
                cout << flush;
                cin >> res;
                if(res == "YES"){
                    ans += 'R';
                    y++;
                }
            }
        }
    }
    string ans2 = "";
    x = y = n;
    while(x + y > n + 1){
        if(y > 0){
            cout << "? 1 1 " << x << " " << y - 1 << endl;
            cout << flush;
            cin >> res;
            if(res == "YES"){
                y--;
                ans2 = 'R' + ans2;
            } else if(x > 0){
                cout << "? 1 1 " << x - 1 << " " << y << endl;
                cout << flush;
                cin >> res;
                if(res == "YES"){
                    x--;
                    ans2 = 'D' + ans2;
                }
            }
        }
    }
    cout << "! " << ans + ans2 << endl;
    return 0;
}
