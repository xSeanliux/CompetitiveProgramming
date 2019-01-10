#include <iostream>
using namespace std;

int h1, m1, h2, m2;

int main(){
    while(cin >> h1 >> m1 >> h2 >> m2){
        if(!(h1 || h2 || m1 || m2)) return 0;
        m1 += h1*60;
        m2 += h2*60;
        m2 -= m1;
        if(m2 < 0) m2 += 1440;
        cout << m2 << endl;
    }
}

