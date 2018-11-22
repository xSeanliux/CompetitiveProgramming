#include <iostream>
using namespace std;
int main(){
    int numberOfArrays;
    int _array[5];
    cin >> numberOfArrays;
    while(numberOfArrays){
        for(int j = 0; j < 4; j++){
            cin >> _array[j];
        }
        if(_array[0] + _array[3] == _array[1] + _array[2]){
            //等差數列
            _array[4] = _array[3] + _array[3] - _array[2];

        } else if (_array[3]/_array[2] == _array[2]/_array[1]){
            //等比數列
            _array[4] = _array[3] * _array[3] / _array[2];
        }

        for(int i = 0; i < 5; i++){
            cout << _array[i] << " ";
        }
        cout << endl;
        numberOfArrays--;

    }


}
