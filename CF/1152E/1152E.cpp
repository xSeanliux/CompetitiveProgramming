#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int maxN = 326;

int main(){
    int N, K, arr[maxN * maxN], a[maxN], b[maxN];
    vector<int> pos[maxN];
    bool has[maxN];
    fill(has, has + maxN, 0);
    cin >> N >> K;
    for(int i = 1; i <= N * K; i++){
        cin >> arr[i];
        pos[(arr[i] + (K - 1) - 1) / (K - 1)].push_back(i);
    }

    for(int i = 1; i <= (N + K - 2) / (K - 1); i++){
        map<int, int> mp = map<int, int>();
        for(int x : pos[i]){
            if(has[arr[x]]) continue;
            if(mp.count(arr[x])){
                b[arr[x]] = (x);
                a[arr[x]] = mp[arr[x]];
                mp = map<int, int>();
                has[arr[x]] = true;
            } else {
                mp[arr[x]] = x;
            }
        }
    }
    for(int i = 1; i <= N; i++) cout << a[i] << " " << b[i] << endl;
}

