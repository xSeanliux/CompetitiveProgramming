#include <iostream>
using namespace std;

int R = 7129;

int Rand(){
    return (R = (R * 3 + 1291) % 10101);
}

struct Node{
    int val, pri, sz;
    Node *l, *r;
    inline unsigned rand(){
        static unsigned x = 7;
        return x = x * 0xdefaced + 1;
    }
    Node(int val): val(val), pri(rand()), l(NULL), r(NULL), sz(1){}
    Node(int val, Node *l, Node *r): val(val), pri(Rand()), l(l), r(r), sz(1){
        this->pull();
    }
    void pull(){
        this->sz = 1;
        if(this->l) this->sz += this->l->sz;
        if(this->r) this->sz += this->r->sz;
    }
    void disp(){
        if(this->l) this->l->disp();
        cout << this->val << endl;
        if(this->r) this->r->disp();
    }
} *root;

int Size(Node *n){
    return n ? n->sz : 0;
}

Node *Merge(Node *a, Node *b){
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

void Split(Node *o, Node *&a, Node *&b, int k){
    if(!o){
        a = NULL;
        b = NULL;
        return;
    }
    if(Size(o->l) >= k){

    }
    if(k <= Size(o->l)){
        b = o;
        Split(o->l, a, b->l, k);
        b->pull();
    } else {
        a = o;
        Split(o->r, a->r, b, k - Size(o->l) - 1);
        a->pull();
    }
}

void Add(int ind, int val){
    Node *a, *b, *c, *d;
    Split(root, a, b, ind - 1);
    b = Merge(new Node(val), b);
    root = Merge(a, b);
}

void Del(Node *&n, int ind){
    if(Size(n->l) >= ind){
        Del(n->l, ind);
    } else if(ind == Size(n->l) + 1){
        n = Merge(n->l, n->r);
    } else {
        Del(n->r, ind - Size(n->l) - 1);
    }
    n->pull();

}

int getMax(Node *n){
    while(n->r){
        n = n->r;
    }
    return n->val;
}

int Query(Node *n, int ind){
    if(Size(n->l) >= ind){
        return Query(n->l, ind);
    } else if(ind == Size(n->l) + 1){
        return n->val;
    } else {
        return Query(n->r, ind - Size(n->l) - 1);
    }
}

int N, M, i, x;
string com;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    cin >> x;
    root = new Node(x);
    for(int i = 0; i < N - 1; i++){
        cin >> x;
        root = Merge(root, new Node(x));
    }
    for(int i = 0; i < M; i++){
        cin >> com;
        if(com == "ADD"){
            cin >> i >> x;
            Add(i, x);
        } else if(com == "LEAVE"){
            cin >> i;
            Del(root, i);
        } else if(com == "QUERY") {
            cin >> i;
            cout << Query(root, i) << endl;
        }
    }
}
