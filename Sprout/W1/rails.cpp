#include <iostream>
#include <stack>
using namespace std;

int T, N, target[(int)1e5 + 10];


int main(){
    cin >> T;
    while(T--){
        cin >> N;
        stack<int> stk;
        for(int i = 0; i < N; i++) cin >> target[i];
        int head = 0;
        bool canDo = true;
        for(int i = 0; i < N && canDo; i++){ //currently doing target[i]
            while(stk.empty() || stk.top() != target[i]){
                if(head == N){
                    canDo = false;
                    break;
                }
                stk.push(++head);
            }
            stk.pop();
        }
        if(canDo) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
