#include <iostream>
#include <stack>
using namespace std;

int N, K, currentIte = 0, m = 0, currentHeight;
bool canDo = true;


int main(){
    cin >> N;
    stack <pair<int, int> > sta; //height, x
    for(int i = 0; i < N; i++){
        cin >> K;
        m = max(K, m);
        if(sta.empty()){
            sta.push(pair<int, int>(K, i));
            currentHeight = K;
        } else {
            while(!sta.empty() && sta.top().first < K){
                if((K - currentHeight) % 2 == 1 && (i - sta.top().second + 1) % 2 == 1){
                    cout << "NO" << endl;
                    return 0;
                } else {
                    sta.pop();
                    if(!sta.empty())
                        currentHeight = sta.top().first;
                }
            }
            if(sta.empty()){
                sta.push(pair<int, int>(K, i));
                currentHeight = K;
            } else if(sta.top().first > K){
                sta.push(pair<int, int>(K, i));
                currentHeight = K;
            } else if((K - currentHeight) % 2 == 1 && (i - sta.top().second + 1) % 2 == 1){
                cout << "NO" << endl;
                return 0;
            } else {
                sta.pop();
                if(!sta.empty())
                    currentHeight = sta.top().first;
            }
        }
    }
    K = m + 1;
    if(sta.empty()){
            sta.push(pair<int, int>(K, N));
            currentHeight = K;
        } else {
            while(!sta.empty() && sta.top().first < K){
                if((K - currentHeight) % 2 == 1 && (N - sta.top().second + 1) % 2 == 1){
                    cout << "NO" << endl;
                    return 0;
                } else {
                    sta.pop();
                    currentHeight = sta.top().first;
                }
            }
            if(sta.empty()){
                sta.push(pair<int, int>(K, N));
                currentHeight = K;
            } else if(sta.top().first > K){
                sta.push(pair<int, int>(K, N));
                currentHeight = K;
            } else if((K - currentHeight) % 2 == 1 && (N - sta.top().second + 1) % 2 == 1){
                cout << "NO" << endl;
                return 0;
            } else {
                sta.pop();
                if(!sta.empty())
                    currentHeight = sta.top().first;
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
