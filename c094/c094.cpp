#include <iostream>
using namespace std;

int things[25]; //max 20;
bool isOn[25];

int main(){
    int i = 0;
    int num, switchTimes, lim;
    int _tmp = 0, sum = 0;
    while(cin >> num >> switchTimes >> lim){

        i++;
        if(num == switchTimes & switchTimes == lim && lim == 0){
            return 0;
        }
        cout << "Sequence " << i << endl;

        for(int i = 0; i < num; i++){
            cin >> things[i];
            isOn[i] = false;
        }
        int max_consumption = 0;
        for(int i = 0; i < switchTimes; i++){
            cin >> _tmp;
            isOn[_tmp-1] = !isOn[_tmp-1]; //the first thing is at index 0, second at index 1 ect
            for(int i = 0; i < num; i++){
                sum += isOn[i]*things[i]; //if it's not on, the value will be 0, and nothing will be added.
            }
            max_consumption = (sum > max_consumption)? sum : max_consumption;
            sum = 0;
        }


        if(max_consumption > lim){
            cout << "Fuse was blown." << endl;
            sum = 0;
        } else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << max_consumption << " amperes." << endl;
            sum = 0;
        }
    }
}
