#include <iostream>
using namespace std;

int n;

int main(){
    while(cin >> n){
        if(!n) return 0;
        if(n % 2 || n == 2){
            cout << "Impossible" << endl;
            continue;
        }
        cout << 3 * n / 2 << endl;
        for(int i = 1; i < n; i++) cout << i << " " << i + 1 << endl;
        cout << n << " " << 1 << endl;
        for(int i = 1; i <= n/2; i++) cout << i << " " << i + n/2 << endl;
    }

}
