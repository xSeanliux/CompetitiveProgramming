#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;




int main(){
    cin >> n >> k; //represent n in k powers
    int currentPow = 1;
    int oriN = n, currentObjs = 0;
    priority_queue <int> que;
    while(oriN){
        if(oriN % 2) {
            que.push(currentPow);
            currentObjs++;
        }
        currentPow *= 2;
        oriN /= 2;
    }
    if(currentObjs > k){
        cout << "NO" << endl;
    } else if(currentObjs == k){
        cout << "YES" << endl;
        cout << que.top();
        que.pop();
        while(!que.empty()){
            cout << " " << que.top();
            que.pop();
        }
        cout << endl;
    } else {
        while(currentObjs < k && !(que.top() == 1)){
            int top = que.top();
            que.pop();
            currentObjs++;
            que.push(top/2);
            que.push(top/2);
        }
        if(currentObjs == k){
            cout << "YES" << endl;
            cout << que.top();
            que.pop();
            while(!que.empty()){
                cout << " " << que.top();
                que.pop();
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
