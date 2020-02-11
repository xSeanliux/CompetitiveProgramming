#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << "1000 1000\n";
    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            cout << "-1 ";
        }
        cout << "\n";
    }
}
