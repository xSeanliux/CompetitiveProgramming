#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, k;

signed main(){
    ericxiao;
    cin >> n >> k;
    if(k >= 1000000 || n < k*(k + 1)/2){
        cout << -1 << endl;
        return 0;
    }
    int sb = n, g;
    for(int i = 1; i*i <= n; i++){
        if(!(n % i)){
            if(i >= k*(k + 1)/2) sb = min(i, sb);
            if(n/i >= k*(k + 1)/2) sb = min(n/i, sb);
        }
    }
    g = n/sb;
    for(int i = 1; i < k; i++){
        cout << i * g << " ";
        n -= i * g;
    }
    cout << n << endl;
}
