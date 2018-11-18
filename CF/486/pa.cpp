#include <iostream>
using namespace std;

int nUni = 0;
int N, K, current, now = 0;
bool has[105];
int main(){
    cin >> N >> K;
    int nums[N];
    for(int i = 0 ; i < 105; i++){
        has[i] = false;
    }
    for(int i = 0 ; i < N; i++){
        cin >> nums[i];
        if(!has[nums[i]]) {has[nums[i]] = true; nUni++;}
    }
    if(nUni >= K){
        cout << "YES" << endl;
        has[nums[0]] = false;
        cout << "1";
        for(int i = 1 ; i < N && K > 1; i++){
            if(has[nums[i]]){
                cout << " " << i + 1;
                has[nums[i]] = false;
                K--;
            }
        }
    } else {
        cout << "NO";
    }
}
