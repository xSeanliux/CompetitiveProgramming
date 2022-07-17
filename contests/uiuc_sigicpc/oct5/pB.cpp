#include <iostream>
using namespace std;

int main(){
    int N, x, cs = 0;
    cin >> N;
    while(N--){
        cin >> x;
        cs ^= (x - 1);
        cout << (((cs & 1) ^ 1) + 1) << endl;
    }
}
