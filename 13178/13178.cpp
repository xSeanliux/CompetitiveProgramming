#include <iostream>
using namespace std;

int c, N;

int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> N;
        if(N % 3 == 1){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}
