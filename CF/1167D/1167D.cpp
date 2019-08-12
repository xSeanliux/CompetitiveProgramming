#include <iostream>
#include <stack>
using namespace std;

stack<int> stk;
string s;
int max_D, N, dep[(int)2e5 + 10];

int main(){
    cin >> N >> s;
    max_D = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == '('){
            if(stk.empty()){
                dep[i] = 0;
            } else {
                dep[i] = dep[stk.top()] + 1;
            }
            stk.push(i);
        } else {
            dep[i] = dep[stk.top()];
            stk.pop();
        }
        max_D = max(max_D, dep[i]);
    }
    for(int i = 0; i < N; i++){
        cout << (dep[i] > max_D/2);
    }
}
