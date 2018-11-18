#include <iostream>
using namespace std;

int n, r;
bool isOn[1004], heaters[1004];


void turnOn(int index){
    for(int i = 0; i < r; i++){
        if(index - i >= 0){
            isOn[index - i] = true;
        }
        if(index + i < n){
            isOn[index + i] = true;
        }
    }
}

int main(){
    cin >> n >> r;
    for(int i = 0 ; i < 1004; i++){
        isOn[i] = heaters[i] = false;
    }
    for(int i = 0 ; i < n; i++){
        cin >> heaters[i];
        //if(heaters[i]) isOn[i] = true;
    }
    int ans = 0;
    bool canDo = true;
    for(int i = 0 ; i < n; i++){
        //cout << "now checking i = " << i << endl;
        if(!isOn[i]){
            //cout << "switching off " << i << endl;
            for(int j = min(i + r - 1, n - 1); j >= max(0, i - r + 1); j--){
                if(heaters[j]){
                    //cout << "Turning on switch at " << j << endl;
                    turnOn(j);
                    //cout << "done turning off" << endl;
                    ans++;
                    i = j;
                    break;
                } else if(j == max(0, i - r + 1)){
                    canDo = false;
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
}
