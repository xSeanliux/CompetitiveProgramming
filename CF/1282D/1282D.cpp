#include <iostream>
#include <string.h>
using namespace std;

int res[305], ea, eb;

int main(){
    cout << "a" << endl;
    cin >> ea;
    if(!ea) return 0;
    int l = ea + 1;
    string s = "";
    for(int i = 0; i < l; i++){
        s += "a";
    }
    int m = 100000, M = - 1;
    for(int i = 0; i < l - 1; i++){
        s[i] = 'b';
        if(i == 17){
            cout << "s = " << s << endl;
        }
        cout << s << endl;
        cin >> res[i];
        if(!res[i]) return 0;
        s[i] = 'a';
        m = min(res[i], m);
        M = max(res[i], M);
    }
    if(m == l - 1){
        for(int i = 0; i < l - 1; i++){
            cout << 'b';
        }
        cout << endl;
        cin >> ea;
        return 0;
    }
    s[l - 1] = 'b';
    cout << s << endl;
    cin >> res[l - 1];
    if(!res[l - 1]) return 0;
    if(l > 13) {
        for(int i = 0; i < l; i++){
            cout << res[i] << " ";
        }
        cout << endl;
        return 0;
    }
    string ans = "";
    for(int i = 0; i < l; i++){
        //if(l > 13) cout << "i = " << i << ", res[" << i << "] = " << res[i] << endl;
        if(res[i] == m) ans += 'b';
        else ans += 'a';
    }
    if(l > 13) cout << "ans = " << ans << endl;
    cout << ans << endl;
    //if(l > 13)
    //    cout << "FINISHED OUTPUT" << endl;
    cin >> ea;
    return 0;

}
