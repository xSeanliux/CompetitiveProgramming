#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int t[3];

int main(){
    while(cin >> t[0] >> t[1] >> t[2]){
        if(t[0] == 0 && t[1] == 0 && t[2] == 0){
            return 0;
        } else {
            sort(t, t+3);
            string ans = (sqrt(t[0]*t[0] + t[1]*t[1]) == t[2]) ? "right" : "wrong";
            cout << ans << endl;
        }
    }
}
