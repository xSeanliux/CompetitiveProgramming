#include <iostream>
#include <string.h>
using namespace std;

int c, ans;
string l1, l2;
int nCars[30];

int main(){
    cin >> c;
    for(int aa = 0 ; aa < c; aa++){
        cin >> l1 >> l2;
        ans = 0;
        for(int i = 0 ; i < 30; i++){
            nCars[i] = 0;
        }
        for(int i = 0  ; i < l1.length(); i++){
            nCars[l1[i] - 'A']++;
        }
        for(int i = 0  ; i < l2.length(); i++){
            nCars[l2[i] - 'A']++;
        }
        for(int i = 0 ; i < 30; i++){
            ans += max(0, nCars[i]-1);
        }
        cout << ans << endl;
    }
}
