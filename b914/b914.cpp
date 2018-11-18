#include <iostream>
#include <math.h>
using namespace std;

int main(){
    float a, total;
    while(cin >> a){
        total = 0;
        for(int i = 0; i < a; i++){
            int _temp;
            cin >> _temp;
            total += _temp;
        }
        if(a != 0){
            cout << "\n" <<  floor(total/a + 0.5) << endl;
        } else cout << 0;


    }
}



