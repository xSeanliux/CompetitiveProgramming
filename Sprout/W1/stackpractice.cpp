#include <iostream>
#include <stack>
using namespace std;

int T, x, y;
stack<int> stk;

int main(){
    cin >> T;
    while(T--){
        cin >> x;
        if(x == 1){
            cin >> y;
            stk.push(y);
        } else {
            if(stk.empty()){
                cout << "empty!" << endl;
            } else {
                cout << stk.top() << endl;
                stk.pop();
            }
        }
    }
}
