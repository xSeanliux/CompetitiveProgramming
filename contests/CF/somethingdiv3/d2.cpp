#include <iostream>
#include <stack>
using namespace std;

int N, K, currentIte = 0, m = 0;
bool canDo = true;


int main(){
    cin >> N;
    stack <pair<int, int> > sta;
    for(int i = 0; i < N; i++){
        cin >> K;
        m = max(K, m);
        if(sta.empty()){
            sta.push(pair<int, int>(K, i));
        } else {
            while(!sta.empty() && sta.top().first < K){
                if((i - sta.top().second + 1) % 2 == 1){
                    cout << "NO" << endl;
                    return 0;
                } else {
                    sta.pop();
                }
            }
            if(sta.empty()){
                sta.push(pair<int, int>(K, i));
            } else if(sta.top().first > K){
                sta.push(pair<int, int>(K, i));
            } else if((i - sta.top().second + 1) % 2 == 1){
                cout << "NO" << endl;
                return 0;
            } else {
                sta.pop();
            }
        }
    }
    while(!sta.empty()){
        if(sta.top().first != m){
            cout << "NO" << endl;
            return 0;
        }
        sta.pop();
    }
    cout << "YES" << endl;
    return 0;
}
