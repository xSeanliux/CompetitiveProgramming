#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#define pair<int,int>
#define F first
#define S second
using namespace std;

vector<int> dsu;
int n, k, a, b, ans = 0;

void Flat(int x){
    if(dsu[x] == x) return;
    Flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

bool Merge(int a, int b){
    Flat(a), Flat(b);
    if(dsu[a] == dsu[b]) return true;
    dsu[dsu[a]] = dsu[b];
    return false;
}

int main(){
    cin >> n >> k;
    dsu.resize(n + 10);
    iota(dsu.begin(), dsu.end(), 0);
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        ans += Merge(a, b);
    }
    cout << ans << endl;
}
