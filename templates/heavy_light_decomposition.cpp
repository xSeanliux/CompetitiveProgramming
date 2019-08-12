#include <iostream>
#include <vector>
using namespace std;
/*
    Input :
    First Line: integer N, meaning there are N vertices
    then N numbers, a_i, a_i is the weight of the ith vertex
    then follows N-1 lines with two numbers a, b, meaning a is connected to b
    then an integer M, meaning M queries
    followed by M lines with three integers c, a, b
    c == 0 means change vertex a to b
    c == 1 means output the sum of the vertex weights from a to b
    good luck!
*/
int N, a, b, c, cnt = 0, M;
vector<vector<int> > adj;
vector<int> head, depth, pos, parent, heavy, weight, arr;
vector<int> segtree;

void build(int id, int l, int r){
    if(l + 1 == r) {
        segtree[id] = arr[l];
        return;
    }
    build(2 * id + 1, l, l + r >> 1);
    build(2 * id + 2, l + r >> 1, r);
    segtree[id] = segtree[2 * id + 1] + segtree[2 * id + 2];
}

int query(int id, int ql, int qr, int l, int r){
    if(ql >= r || qr <= l) return 0;
    if(ql <= l && r <= qr) return segtree[id];
    return query(2 * id + 1, ql, qr, l, l + r >> 1) + query(2 * id + 2, ql, qr, l + r >> 1, r);
}

void upd(int id, int l, int r, int pos, int val){
    if(l + 1 == r){
        segtree[id] = val;
        return;
    }
    if(pos < l + r >> 1) upd(2 * id + 1, l, l + r >> 1, pos, val);
    else upd(2 * id + 2, l + r >> 1, r, pos, val);
    segtree[id] = segtree[2 * id + 1] + segtree[2 * id + 2];
}

int dfs(int current){
    int sz = 1, max_size = 0, _sz;
    for(int con : adj[current]){
        if(con != parent[current]){
            parent[con] = current;
            depth[con] = depth[current] + 1;
            _sz = dfs(con);
            sz += _sz;
            if(_sz > max_size){
                max_size = _sz;
                heavy[current] = con;
            }
        }
    }
    return sz;
}


int getSum(int a, int b){
    int ans = 0;
    for(; head[a] != head[b]; b = parent[head[b]]){
        if(depth[head[a]] > depth[head[b]])
            swap(a, b);
        ans += query(0, pos[head[b]], pos[b] + 1, 0, N);
        cout << "pos[b]: " << pos[b] << ", pos[head[b]]: " << pos[head[b]] << endl;
    }
    if(depth[a] > depth[b]) swap(a, b);
    ans += query(0, pos[a], pos[b] + 1, 0, N);
    cout << "query(pos[" << a << "], pos[" << b << "]) = " << query(0, pos[a], pos[b] + 1, 0, N) << endl;
    return ans;
}

void decompose(int current, int ori){
    cout << "Running decom(" << current << ", " << ori << ")" << endl;
    head[current] = ori; pos[current] = cnt++;
    if(heavy[current] != -1) decompose(heavy[current], ori);
    for(int i : adj[current]){
        if(i != parent[current] && i != heavy[current])
            decompose(i, i);
    }
}

int main(){
    cin >> N;

    //init
    adj.resize(N);
    head.resize(N);
    depth.resize(N);
    pos.resize(N);
    weight.resize(N);
    parent.resize(N);
    heavy.resize(N);
    arr.resize(N);
    segtree.resize(4 * N);
    //init

    for(int i = 0; i < N; i++) cin >> weight[i];
    for(int i = 0; i < N; i++) heavy[i] = -1;
    for(int i = 1; i < N; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);
    decompose(0, 0);
    for(int i = 0; i < N; i++){
        arr[ pos[i] ] = weight[i];
    }
    build(0, 0, N);
    cin >> M;
    while(M--){
        cin >> c;
        if(c == 0){ //update node a to b
            cin >> a >> b;
            upd(0, 0, N, pos[a], b);
        } else { //query node a - b
            cin >> a >> b;
            cout << getSum(a, b) << endl;
        }
    }
}
