#include <iostream>
using namespace std;

int T;

int a, b;

int main(){
    cin >> T;
    while(T--){
        cin >> a >> b;
        if(!(a % b)){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
