#include <iostream>
using namespace std;
int main(){
    long long blocks;
    while(cin >> blocks){

        if(blocks % 4 == 0){
            cout << "egg" << endl;
        } else {
            cout << "fat" << endl;
        }
    }
}
