#include <iostream>
using namespace std;
int main(){
    int steps, diff;
    while(cin >> steps >> diff){
        if(steps == 0){
            cout << "Ok!" << endl;
        } else if(diff == 0){
            cout << "Impossib1e!" << endl;
        } else if (steps % diff == 0){
            cout << "Ok!" << endl;
        } else {
            cout << "Impossib1e!" << endl;
        }

    }
}
