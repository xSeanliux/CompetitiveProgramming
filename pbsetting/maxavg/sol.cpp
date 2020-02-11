#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int x, n, m, ans = 0;

int main(){
    ericxiao;
    cin >> n >> m;
    for(int i = 0; i < n * m; i++){
        cin >> x;
        ans = max(ans, x);
    }
    cout << ans << '\n';
}
