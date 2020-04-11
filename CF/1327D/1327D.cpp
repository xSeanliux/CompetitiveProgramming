#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5 + 10;

int p[maxN], c[maxN], T, N, ans = maxN;
bool visited[maxN];
void solve(){
    cin >> N;
    ans = N;
    for(int i = 1; i <= N; i++) cin >> p[i];
    for(int i = 1; i <= N; i++) cin >> c[i];
    fill(visited, visited + N + 1, false);
    vector<int> vec;
    for(int i = 1; i <= N; i++){
        if(visited[i]) continue;
        int t = i;
        vector<int>().swap(vec);
        while(!visited[t]){
            vec.push_back(c[t]);
            visited[t] = true;
            t = p[t];
        }
        for(int d = 1; d * d <= vec.size(); d++){
            if(!(vec.size() % d)){
                for(int k = 0; k < d; k++){
                    for(int r = k; r < vec.size(); r += d){
                        if(vec[k] != vec[r]) break;
                        else if(r + d >= vec.size()) ans = min(ans, d);
                    }
                }
                for(int k = 0; k < vec.size() / d; k++){
                    for(int r = k; r < vec.size(); r += vec.size() / d){
                        if(vec[k] != vec[r]) break;
                        else if(r + vec.size() / d >= vec.size()) ans = min(ans, (int)vec.size() / d);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    cin >> T;
    while(T--){
        solve();
    }
}
