#include <iostream>
using namespace std;

int n, e, d;

int main(){
    cin >> n >> e >> d;
    d *= 5;
    int ans = n;
    for(int i = 0; i * d <= n; i++){
        if(i * d > n) break;
        ans = min(ans, (n - i * d) % e);
    }
    cout << ans << endl;
}
