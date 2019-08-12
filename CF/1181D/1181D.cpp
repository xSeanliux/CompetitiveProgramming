#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define int long long int
using namespace std;

int N, M, Q, k, t;
vector<int> times;
vector<pii> cties;

int r = 1118;

int Rand(){
    return r = (r * r + 100101) % 0xdefaced;
}

struct Node{
    Node *l, *r;
    int val, sz, pri;
    Node(): val(-1){}
    Node(int val): val(val), l(NULL), r(NULL), sz(1), pri(Rand()){}
    Node(Node *lNode, Node *rNode): l(lNode), r(rNode), pri(Rand()){
        pull();
    }
    void pull(){sz = 1; if(l) sz += l->sz; if(r) sz += r->sz;}
} *root;

Node* Merge(Node *a, Node *b){
    if(!a || !b) return a ? a : b;
    if(a->pri < b->pri){
        a->r = Merge(a->r, b);
        a->pull();
        return a;
    }
    b->l = Merge(a, b->l);
    b->pull();
    return b;
}

int Size(Node *n){
    return n ? n->sz : 0;
}

void Split(Node *o, Node *&a, Node *&b, int k){
    if(!o){
        a = b = NULL;
        return;
    }
    o->pull();
    if(o->val < k){
        a = o;
        Split(o->r, a->r, b, k);
        a->pull();
    } else {
        b = o;
        Split(o->l, a, b->l, k);
        b->pull();
    }
}

int getKth(Node *o, int k){
    Node *n = o;
    while(n){
        if(Size(n->l) + 1 == k) return n->val;
        if(Size(n->l) + 1 < k){
            k -= Size(n->l) + 1;
            n = n->r;
        } else {
            n = n->l;
        }
    }
}

Node *ins(Node *root, int val){
    Node *a, *b;
    Split(root, a, b, val);
    root = Merge(Merge(a, new Node(val)), b);
    return root;
}

int sub(int a, int b, int m){
    return (a - b + ((a-b+m+1)/m) * m) % m;
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;
    //N olympiads, M cities
    times.resize(M + 1);
    fill(times.begin(), times.end(), 0);
    for(int i = 0; i < N; i++){
        cin >> t;
        times[t]++;
    }
    int maxTime = 0;
    for(int i = 1; i <= M; i++){
        cties.push_back({times[i], i});
        maxTime = max(times[i], maxTime);
    }
    sort(cties.begin(), cties.end());
    vector<int> ans;
    vector<pii> queries; //query, id
    ans.resize(Q + 5);
    for(int i = 0; i < Q; i++){
        cin >> t;
        queries.push_back({t - N, i});
    }
    sort(queries.begin(), queries.end());
    int x, id = 0;
    bool f = true;
    root = NULL;
    if(cties[0].first == maxTime){ //everything is just mod, do later
        for(auto p : queries){
            ans[p.second] = (p.first - 1 + M) % M + 1;
        }
        f = false;
    }

    if(f){
        int currentTime = 0, prevTime = 0;
        bool flg = true;
        for(int i = 0; i <= M && id < Q; i++){
            if(cties[i].first == maxTime){ //update the remaining, then break
                while(id < Q){
                    ans[queries[id].second] = sub(queries[id].first, currentTime + 1, M) + 1;
                    id++;
                }
                break;
            }
            int k = cties[i].first;
            while(cties[i].first == k){
                root = ins(root, cties[i].second);
                i++;
            }
            i--;
            prevTime = currentTime;
            currentTime += root->sz * (cties[i + 1].first - cties[i].first);
            while(id < Q && queries[id].first <= currentTime){
                ans[queries[id].second] = getKth(root, sub(queries[id].first, prevTime + 1, root->sz) + 1);
                id++;
            }
        }
    }


    for(int i = 0; i < Q; i++){
        cout << ans[i] << endl;
    }
}
