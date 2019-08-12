#include <iostream>
using namespace std;

const int maxN = 1e5;
int N, arr[maxN + 10], ind[maxN + 10];
bool win[maxN + 10];

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        ind[arr[i]] = i;
    }
    win[ind[N]] = false;
    bool currentWin;
    for(int i = N - 1; i >= 1; i--){
        currentWin = false;
        for(int j = ind[i]; j <= N; j += i){
            //cout << "Checking ind = " << j << "arr[" << j << "] = " << arr[j] << ", win[" << j << "] = " << win[j] << endl;
            if(arr[j] > i && !win[j]) currentWin = true;
        }
        for(int j = ind[i]; j >= 1; j -= i){
            //cout << "Checking ind = " << j << "arr[" << j << "] = " << arr[j] << ", win[" << j << "] = " << win[j] << endl;
            if(arr[j] > i && !win[j]) currentWin = true;
        }
        win[ind[i]] = currentWin;
        //cout << "WIN[" << i << "] at " << ind[i] << " = " << win[ind[i]] << endl;
    }
    for(int i = 1; i <= N; i++) cout << (win[i] ? "A" : "B");
}
