#include <iostream>
#include <set>
#include <algorithm>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


const int maxN = 2e5;

int dsu[(maxN << 1) + 10], N, M, q, a, b;
set<int> st;

void flat(int a){
    if(dsu[a] == a) return;
    flat(dsu[a]);
    dsu[a] = dsu[dsu[a]];
}

void Merge(int a, int b){
    flat(a); flat(b);
    dsu[dsu[a]] = dsu[b];
}

int main(){
    ericxiao;
    cin >> N >> M >> q;
    iota(dsu, dsu + (N + M) + 5, 0);
    while(q--){
        cin >> a >> b;
        Merge(a - 1, b + N - 1);
    }
    for(int i = 0; i < (N + M); i++){
        flat(i);
        st.insert(dsu[i]);
    }
    cout << st.size() - 1 << endl;
}
