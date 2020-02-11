#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int lim = 150001;

int n, cnt[150005], x;

int main(){
    ericxiao;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        cnt[x]++;
    }
    for(int i = 1; i < lim; i++){
        if(!cnt[i] && cnt[i + 1]){
            cnt[i]++;
            cnt[i + 1]--;
        }
    }
    for(int i = lim + 1; i > 0; i--){
        if(!cnt[i] && cnt[i - 1]){
            cnt[i]++;
            cnt[i - 1]--;
        }
    }
    int ans = 0;
    for(int i = 0; i <= lim + 1; i++){
        ans += (cnt[i] > 0);
    }
    cout << ans << endl;
}
