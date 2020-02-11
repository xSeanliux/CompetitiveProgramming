#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <set>
#define int long long int
using namespace std;


int n, t, a, b ,c;

signed main(){
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> a >> b >> c;
        for(int i = 0; i <= a; i++){
            for(int j = 0; j <= b; j++){
                if(i <= a && (2 * i + j) <= b && 2 * j <= c){
                    ans = max(ans, 3 * (i + j));
                }
            }
        }
        cout << ans << endl;
    }
}
