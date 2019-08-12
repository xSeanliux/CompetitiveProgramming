#include <iostream>
#include <set>
using namespace std;

int N, M, a, b, dsu[50005], ans, c = 0;
set<int> s;

void flat(int k){
    if(dsu[k] == k) return;
    flat(dsu[k]);
    dsu[k] = dsu[dsu[k]];
}



int main(){
    while(cin >> N >> M){
        if(!(N | M)) return 0;
        for(int i = 1; i <= N; i++) dsu[i] = i;
        while(M--){
            cin >> a >> b;
            flat(a); flat(b);
            dsu[dsu[a]] = dsu[b];

        }
        s.clear();
        ans = 0;
        for(int i = 1; i <= N; i++){
            flat(i);
            if(!s.count(dsu[i])){
                ans++;
                s.insert(dsu[i]);
            }
        }
        printf("Case %d: %d\n", ++c, ans);
    }
}
