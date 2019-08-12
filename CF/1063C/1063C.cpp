#include <iostream>
#include <string.h>
using namespace std;

int n, l1 = 0, l2 = 0, r1 = 1e9, r2 = 1e9, m1 = (l1 + r1) / 2, m2 = (l2 + r2)  / 2;
string col;
int main(){
    cin >> n;
    for(int i = 0; i < n/2; i++){ //y = 0 -> (m, 0)
        cout << m1 << " 0" << endl;
        cout << flush;
        cin >> col;
        if(col == "white"){
            l1 = m1 + 1;
        } else {
            r1 = m1 - 1;
        }
        m1 = (l1 + r1) / 2;
    }
    for(int i = n/2; i < n; i++){ //x = 0
        cout << "0 " << m2 << endl;
        cout << flush;
        cin >> col;
        if(col == "white"){
            l2 = m2 + 1;
        } else {
            r2 = m2 - 1;
        }
        m2 = (l2 + r2) / 2;
    }
    cout << m1 << " 0 0 " << m2 << endl;
    return 0;
}
