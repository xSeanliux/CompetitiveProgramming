#include <iostream>
using namespace std;
int holes;

int main(){
    cin >> holes;
    if(holes == 1){
        cout << "0" << endl;
    } else {
        if(holes == 0){
            cout << "1" << endl;
            return 0;
        }
        if(holes % 2 == 1){
            cout << "4";
            holes--;
        }
        while(holes >= 2){
            cout << "8";
            holes-=2;
        }
        cout << endl;
    }
}
