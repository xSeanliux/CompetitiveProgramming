#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 1e5;
int bit[maxN + 5], ans[maxN + 5], N, x, y, z;

void modify(int val, int pos){
    for(int i = pos; i <= maxN; i += i & -i){
        bit[i] += val;
    }
}

int query(int pos){
    int a = 0;
    for(int i = pos; i > 0; i -= i & -i){
        a += bit[i];
    }
    return a;
}

struct Query{
    int x, y, z, id;
    bool type; //0 for left, 1 for right
    Query(){}
    Query(int x, int y, int z, int id): x(x), y(y), z(z), id(id){}
    void setType(bool b){
        this->type = b;
    }
};

bool cmpX(const Query a, const Query b){
    if(a.x == b.x && a.y == b.y) return a.z < b.z;
    if(a.x == b.x) return a.y < b.y;
    return a.x > b.x;
}


bool cmpY(const Query a, const Query b){
    if(a.y == b.y) return a.z < b.z;
    return a.y > b.y;
}


vector<Query> queries;

void CDQ(vector<Query> &q){
    //cout << q.size() << endl;
    if(q.size() <= 1){
        //cout << "Returning" << endl;
        return;
    }

    vector<Query> l, r;
    for(int i = 0; i < q.size(); i++){
        (i < q.size()/2 ? l : r).push_back(q[i]);
    }
    CDQ(l); CDQ(r);
    //do tag thing
    for(Query &qu : l) qu.setType(0);
    for(Query &qu : r) qu.setType(1);
    merge(l.begin(), l.end(), r.begin(), r.end(), q.begin(), cmpY); //q is now sorted by Y
    //solve 2D problem
    for(Query qu : q){
        //left  ->modify
        //right ->query
        if(qu.type){ //query
            ans[qu.id] += query(maxN) - query(qu.z);
        } else { //modify
            modify(1, qu.z);
        }
    }
    //undo
    for(Query qu : q){
        //left  ->modify
        //right ->query
        if(!qu.type){ //query
            modify(-1, qu.z);
        }
    }

}


int main(){
    cin >> N;
    queries.resize(N);
    for(int i = 0; i < N; i++){
        cin >> x >> y >> z;
        queries[i] = Query(x, y, z, i);
    }
    sort(queries.begin(), queries.end(), cmpX); //make sure first dimension is sorted
    CDQ(queries);
    //cout << "Done" << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << endl;
}
