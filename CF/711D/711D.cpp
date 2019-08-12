#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int unsigned long long int
using namespace std;

const int maxN = 2e5, MOD = 1e9 + 7;

int N, arr[maxN + 10];
bool visited[maxN + 10];

int exp(int b, int e){
    if(!b) return 0;
    if(!e) return 1;
    int res = exp(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

signed main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        arr[i]--;
    }
    fill(visited, visited + N, false);
    vector<int> vec;
    int ans = 1;
    for(int i = 0; i < N; i++){
        if(visited[i]) continue;
        vec.clear();
        int cnt = 0, now = i;
        while(!visited[now]){
            visited[now] = true;
            cnt++;
            vec.push_back(now);
            now = arr[now];
        }
        if(*lower_bound(vec.begin(), vec.end(), now) == now){
            int len = vec.size() - (lower_bound(vec.begin(), vec.end(), now) - vec.begin());
            //cout << "len = " << len << endl;
            ans = ans * (exp(2, len) - 2) % MOD;
            ans = ans * exp(2, vec.size() - len) % MOD;
        } else {
            ans = ans * exp(2, cnt) % MOD;
        }
    }
    cout << ans << endl;
}
