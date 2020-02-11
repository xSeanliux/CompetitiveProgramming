#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int D = 1000, N = 5e5;
int q, t, x, y, arr[N + 10], smal[D][D], ans;

int main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> t >> x >> y;
        if(t == 1){ //modify
            arr[x] += y;
            for(int i = 1; i < D; i++){
                smal[i][ (x % i) ] += y;
            }
        } else { //query
            ans = 0;
            if(x >= D){
                for(int i = y; i <= N; i += x){
                    ans += arr[i];
                }
            } else {
                ans = smal[x][y];
            }
            cout << ans << endl;
        }
    }
}
