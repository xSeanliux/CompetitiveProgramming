#include <iostream>
using namespace std;

int C, target, N;

int main(){
    cin >> C;
    while(C--){
        cin >> target >> N;
        int stuff[N], powNum = 1 << N, currentSum = 0, _t, counter;
        bool canDo = false;
        for(int i = 0 ; i < N; i++){
            cin >> stuff[i];
        }
        for(int i = 0 ; i < powNum; i++){
            currentSum = counter = 0;
            _t = i;
            while(_t > 0){
                currentSum += stuff[counter] * (_t % 2);
                _t /= 2;
                counter++;
            }
            //cout << currentSum << endl;
            if(currentSum == target){
                canDo = true;
                break;
            }
        }
        if(canDo){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
