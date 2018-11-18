#include <iostream>
using namespace std;
int main(){
    int a, ans;

    while(cin >> a){
        ans = a*(a-1)/2 + 1; //The sum of all integers smaller than a plus one -> top: 1, base is a-1, height is a, Area: (a-1+1)*(a-1)/2 = a*(a-1)/2
        cout << ans << endl;
    }
}
