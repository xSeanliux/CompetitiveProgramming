#include <iostream>
#include <numeric>
#define pii pair<int,int>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 202625;
int N, M, u, v, dsu[maxN], maxTo[maxN];

void Flat(int x){
    if(dsu[x] == x) return;
    Flat(dsu[x]);
    maxTo[x] = maxTo[dsu[x]];
    dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
    Flat(a);
    Flat(b);
    if(dsu[a] == dsu[b]) return;
    maxTo[dsu[b]] = max(maxTo[dsu[b]], maxTo[dsu[a]]);
    dsu[dsu[a]] = dsu[b];
}




int main(){
    ericxiao;
    cin >> N >> M;
    iota(maxTo, maxTo + N + 1, 0);
    iota(dsu, dsu + N + 1, 0);
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        Merge(u, v);
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        Flat(i);
        for(int j = i; j <= maxTo[i]; j++){
            Flat(j);
            Flat(i);
            if(dsu[j] != dsu[i]){
                Merge(j, i);
                ans++;
            }
        }
        i = maxTo[i];
    }
    cout << ans << endl;
}
