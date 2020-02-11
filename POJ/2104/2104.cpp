#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

const int maxN = 100000;

struct Node{
    Node *lNode, *rNode;
    int sum;
    Node(): sum(0), lNode(NULL), rNode(NULL){}
    void pull(){
        sum = 0;
        if(lNode) sum += lNode->sum;
        if(rNode) sum += rNode->sum;
    }
    Node(Node *l, Node *r): lNode(l), rNode(r), sum(0){
        pull();
    }
} *segs[maxN + 10];


Node* init(int l, int r){
    if(l + 1 == r) return new Node();
    return new Node(init(l, (l + r) >> 1), init((l + r) >> 1, r));
}

Node *modify(Node *o, int l, int r, int pos){
    if(l + 1 == r){
        Node *n = new Node();
        n->sum = o->sum + 1;
        return n;
    }
    int mid = (l + r) >> 1;
    if(pos < mid){
        return new Node(modify(o->lNode, l, mid, pos), o->rNode);
    } else {
        return new Node(o->lNode, modify(o->rNode, mid, r, pos));
    }
}

int query(Node *a, Node *b, int l, int r, int k){
    if(l + 1 == r) return l;
    int V = b->lNode->sum - a->lNode->sum;
    if(V < k){
        return query(a->rNode, b->rNode, (l + r) >> 1, r, k - V);
    } else {
        return query(a->lNode, b->lNode, l, (l + r) >> 1, k);
    }
}


int N, M, x, arr[maxN + 10];
vector<int> sor, bk;
signed main(){ //one base
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        sor.push_back(arr[i]);
    }
    sort(sor.begin(), sor.end());
    unique(sor.begin(), sor.end());
    int maxVal = sor.size() + 1;
    segs[0] = init(0, maxVal);
    bk.resize(maxVal);
    int G;
    for(int i = 1; i <= N; i++){
        G = lower_bound(sor.begin(), sor.end(), arr[i]) - sor.begin();
        bk[G] = arr[i];
        arr[i] = G;
        segs[i] = modify(segs[i - 1], 0, maxVal, arr[i]);
    }
    int A, B, K;
    for(int i = 0; i < M; i++){
        cin >> A >> B >> K;
        cout << bk[query(segs[A - 1], segs[B], 0, maxVal, K)] << '\n';
    }
}
