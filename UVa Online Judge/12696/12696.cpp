#include <iostream>
using namespace std;

int t, ans, current;
float wi, hei, len, wei;

int main(){
    cin >> t;
    for(int i = 0 ; i < t; i++){
        cin >> wi >> hei >> len >> wei;
        current = (wei <= 7 && (wi + hei + len <= 125 || (wi <= 56 && hei <= 45 && len <= 25)));
        ans += current;
        cout << current << endl;
    }
    cout << ans << endl;
}
