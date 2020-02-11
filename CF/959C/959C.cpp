#include <iostream>
#define endl '\n'
using namespace std;

int n;

int main(){
    cin >> n;
    if(n <= 5){
        cout << -1 << endl;
    } else {
        for(int i = 2; i <= n - 2; i++){
            cout << i << " " << 1 << endl;
        }
        cout << n - 1 << " " << 2 << endl;
        cout << n << " " << 2 << endl;
    }
    for(int i = 2; i <= n; i++){
        cout << i << " " << i - 1 << endl;
    }

}
