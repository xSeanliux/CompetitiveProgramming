#include <iostream>
#include <algorithm>
using namespace std;

int t, c[3];

int main(){
    cin >> t;
    while(t--){
        for(int i = 0; i < 3; i++) cin >> c[i];
        sort(c, c + 3);
        if(c[2] - 1 <= c[0] + c[1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
