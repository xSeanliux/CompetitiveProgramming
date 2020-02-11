#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e7 + 10;

int N, k;
bool arr[maxN];

int main(){
    ericxiao;
    cin >> N >> k;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int l = 0, r = 0, ans = 0, zs = 0;
    while(r < N){
        while(zs <= k){
            ans = max(ans, r - l);
            zs += (!arr[r++]);
        }
        while(zs > k){
            zs -= (!arr[l++]);
        }
    }
    cout << ans << endl;
}
