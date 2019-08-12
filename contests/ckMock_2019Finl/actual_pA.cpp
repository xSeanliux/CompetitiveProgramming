#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, a, b, c;

const int maxN = 6e5;
int maxSz;
bool needSort[maxN + 10];
vector<int> bit[maxN + 10];

void modify(int x, int y){
    for(int i = x; i <= maxSz; i += (i & -i)){
        //cout << "MOD: " << i << endl;
        bit[i].push_back(y);
        needSort[i] = true;
    }
}

int query(int x, int y){
    int ans = 0;
    for(int i = x; i > 0; i -= (i & -i)){
        if(needSort[i]){
            sort(bit[i].begin(), bit[i].end());
            needSort[i] = false;
        }
        ans += lower_bound(bit[i].begin(), bit[i].end(), y) - bit[i].begin();
    }
    return ans;
}


struct Query{
    int a, b, c;
    Query(){}
    Query(int a, int b, int c): a(a), b(b), c(c){}
} q;

vector<int> sted;
vector<Query> queries;

int main(){
    ericxiao;
    cin >> N;
    queries.resize(N);
    for(int i = 0; i < N; i++){
        cin >> a >> b >> c;
        queries[i] = Query(a, b, c);
        sted.push_back(b);
        sted.push_back(c);
    }
    sort(sted.begin(), sted.end());
    unique(sted.begin(), sted.end());
    maxSz = sted.size();

    for(Query &q : queries){
        //cout << "Query: " << q.a << ", " << q.b << ", " << q.c << endl;
        q.b = lower_bound(sted.begin(), sted.end(), q.b) - sted.begin();
        q.c = lower_bound(sted.begin(), sted.end(), q.c) - sted.begin();
        //cout << "Query: " << q.a << ", " << q.b << ", " << q.c << endl;
        if(q.a == 1){
            modify(q.b, q.c);
        } else {
            cout << query(maxSz, maxSz) - query(q.b, maxSz) - query(maxSz, q.c) + 2 *query(q.b, q.c) << '\n';
        }
    }
}
