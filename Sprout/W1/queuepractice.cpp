#include <iostream>
#include <queue>
using namespace std;

queue<int> que;
int T, x, y;

int main(){
    cin >> T;
    while(T--){
        cin >> x;
        if(x == 1){
            cin >> y;
            que.push(y);
        } else {
            if(que.empty()){
                cout << "empty!" << endl;
            } else {
                cout << que.front() << endl;
                que.pop();
            }
        }
    }
}
