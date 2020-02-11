#include <iostream>
#include <map>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 226;

int ttttttt, N, arr[maxN];

int main(){
    ericxiao;
    cin >> ttttttt;
    while(ttttttt--){
        cin >> N;
        int totones = 0, tottwos = 0;
        for(int i = 0; i < 2 * N; i++){
            cin >> arr[i];
            if(arr[i] == 1) totones++;
            else if(arr[i] == 2) tottwos++;
        }
        map<int,int> mp;
        int ones = 0, twos = 0, cnt = 0;
        mp[totones] = 0;
        for(int i = N - 1; i >= 0; i--){
            cnt++;
            if(arr[i] == 1) ones++;
            else if(arr[i] == 2) twos++;
            if(mp.count(totones + twos - ones)) continue;
            mp[totones + twos - ones] = cnt;
        }
        ones = twos = cnt = 0;
        int ans = 2 * N;
        if(mp.count(tottwos)){
            ans = min(ans, mp[tottwos]);
        }
        for(int i = N; i < 2 * N; i++){
            cnt++;
            if(arr[i] == 1) ones++;
            else if(arr[i] == 2) twos++;
            if(mp.count(tottwos + ones - twos)) ans = min(ans, mp[tottwos + ones - twos] + cnt);
        }
        cout << ans << endl;
    }
}
