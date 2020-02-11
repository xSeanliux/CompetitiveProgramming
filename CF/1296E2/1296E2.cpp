#include <iostream>
#include <queue>
using namespace std;

const int maxN = 2e5, maxZ = 30 + 'a';

queue<int> ids[maxZ];
bool f;
int ans[maxN], N, cnt = 0;
string s;

int main(){
    cin >> N >> s;
    for(int i = 0; i < N; i++){
        f = false;
        for(int c = s[i]; c >= 'a'; c--){
            if(ids[c].size()){
                ans[i] = ids[c].front();
                ids[c].pop();
                f = true;
                break;
            }
        }
        if(!f){
            ans[i] = ++cnt;
        }
        ids[s[i]].push(ans[i]);
    }
    cout << cnt << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}
