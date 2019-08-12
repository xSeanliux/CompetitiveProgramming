#include <iostream>
using namespace std;

long long int m, n, r, c, T;

int main(){
    cin >> T;
    while(T--){
        cin >> m >> n >> r >> c;
        int res = (r) ^ (m - r - 1) ^ (c) ^ (n - c - 1);
        if(res == 0){
            cout << "Hansel" << endl;
        } else {
            cout << "Gretel" << endl;
        }
    }
}
