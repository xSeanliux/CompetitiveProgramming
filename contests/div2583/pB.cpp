#include <iostream>
using namespace std;

//i take t of them, then i will have tn cards
//in any poportions? tn >= b  +g
//a boys and n - a girls come
//a is from 0 to min(n, b)
//n - a is from 0 to min(n, g)
inline int cei(int a, int b){
    return (a + b - 1) / b;
}
int b, g, n;
int main(){
    cin >> b >> g >> n;
    int ans = 0;
    for(int a = 0; a <= min(n, b); a++){
        if(n - a > g) continue;
        ans++;
    }
    cout << ans << endl;
}
