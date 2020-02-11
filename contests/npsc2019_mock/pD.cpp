#include <iostream>
#include <string.h>
using namespace std;

string s;

int main(){
    int l = 1, r = 1001, m = (l + r) / 2;
    while(l + 1 < r){
        cout << m << endl;
        cout << flush;
        cin >> s;
        if(s == "correct") return 0;
        if(s == "higher") l = m + 1;
        else r = m;
        m = (l + r) / 2;
    }
    cout << l << endl;
}
