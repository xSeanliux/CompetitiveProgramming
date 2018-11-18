#include <iostream>
#include <math.h>
using namespace std;

int A, B;


int main(){
    while(cin >> A >> B){
        int ans = (A - B) ^ 1;
        if(!ans) cout << 2 << endl;
        else    cout << ans << endl;
    }
}
