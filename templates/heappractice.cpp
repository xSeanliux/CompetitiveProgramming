#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int T, com, arg;
priority_queue<int, vector<int>, greater<int> > pq;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> com;
        if(com == 1){
            cin >> arg;
            pq.push(arg);
        } else {
            if(pq.empty()){
                cout << "empty!" << endl;
            } else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }
}
