#include <iostream>
#include <stack>
#include <string.h>
#define int long long int
using namespace std;

struct Obj{
    int type, val, ans; //0 for add, 1 for for
    Obj(){}
    Obj(int type, int val): type(type), val(val), ans(0){}
};

int N, com, maxV = (1LL << 32);
string s;

stack<Obj> stk;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    while(N--){
        cin >> s;
        Obj o;
        if(s == "for"){
            cin >> com;
            stk.push(Obj(1, com));
        } else if(s == "add") {
            stk.push(Obj(0, 1));
        } else {
            int res = 0, mult;
            while(stk.top().type != 1){
                res += stk.top().val;
                stk.pop();
            }
            mult = stk.top().val;
            stk.pop();
            stk.push(Obj(0, mult * res));
            if(mult * res >= maxV){
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
        }
    }
    int ans = 0;
    while(stk.size()){
        ans += stk.top().val;
        stk.pop();
        if(ans >= maxV){
            cout << "OVERFLOW!!!" << endl;
            return 0;
        }
    }
    cout << ans << endl;

}
