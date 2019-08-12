#include <iostream>
using namespace std;

int T, x;

int main(){
    cin >> T;
    while(T--){
        cin >> x;
        cout << x*(x-1)/2 + x*(x-1)*(x-2)*(x-3)/24 + 1 <<endl;
    }
}
