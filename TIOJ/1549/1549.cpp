#include <iostream>
#include <stack>
#define int long long int
using namespace std;

int N, ans = 0, x;
stack<int> stk;

signed main(){
    cin >> N;
    int p;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(stk.empty()){
            stk.push(x);
            continue;
        }
        if(stk.top() < x){
            ans += (stk.top() - x) * (stk.top() - x);
            stk.push(x);
            //cout << "Connecting " << stk.top() << " to " << x << endl;
            continue;
        }
        while(stk.size() && stk.top() > x){
            p = stk.top();
            stk.pop();
        }
        if(stk.size()){ //not root
            ans -= (stk.top() - p) * (stk.top() - p);
            ans += (stk.top() - x) * (stk.top() - x) + (x - p) * (x - p);
            //cout << x << " connects to " << p << " and " << stk.top() << endl;
        } else { //is root
            ans += (p - x) * (p - x);
            //cout << x << " is now root, and connects to " << p << endl;
        }
        stk.push(x);
    }
    cout << ans << endl;
}
