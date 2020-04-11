#include <iostream>
#include <vector>
#include <set>
#include <numeric>
#include <algorithm>
using namespace std;

const int maxN = 26;

int N, K, P, a, b, ord[maxN], ans;
set<int> adj[maxN];

inline int Abs(int x){
    return (x < 0 ? -x : x);
}

inline int prv(int x){
    return (x == 0 ? N - 1 : x - 1);
}

bool isValid(){
    for(int i = 0; i < N; i++){
        if(Abs(ord[i] - ord[prv(i)]) > P) return false;
        if(adj[ord[prv(i)]].count(ord[i])) return false;
    }
    return true;
}

int main(){
    cin >> N >> K >> P;
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        adj[a].insert(b);
    }
    ord[0] = N;
    iota(ord + 1, ord + N, 1);
    do{
        if(isValid()){
            ans++;
            //for(int i = 0; i < N; i++) cout << ord[i] << " \n"[i == N - 1];
        }
    } while(next_permutation(ord + 1, ord + N));
    cout << ans << endl;
}
