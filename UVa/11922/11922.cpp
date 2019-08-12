#include <iostream>
#include <vector>
#define lld long long int
using namespace std;

lld seed = 1010101;

lld Rand(){
    return seed = (seed * seed + 1) % (lld)(1e9 + 7);
}

struct Node{
    lld v, sz, f, pri;
    Node *l, *r;
    Node(lld v): v(v), pri(Rand()), sz(1), f(0){}
    Node(){}
    void pull(){
        sz = 1;
        if(l)
            sz += l->sz;
        if(r)
            sz += r->sz;
    }
    void push(){
        if(f){
            f = false;
            swap(l, r);
            if(l) l->f = !(l->f);
            if(r) r->f = !(r->f);
        }
    }
} *root;

Node* Merge(Node *a, Node *b){
    if(!a | !b) return (a ? a : b);
    a->push(); b->push();
    if(a->pri < b->pri){
        a->r = Merge(a->r, b);
        a->pull(); b->pull();
        return a;
    } else {
        b->l = Merge(a, b->l);
        a->pull(); b->pull();
        return b;
    }
}

void Split(Node *o, Node *&a, Node *&b, int R){
    if(!o){
        a = b = NULL;
        return;
    }
    if(!R){
        a = NULL;
        o->push();
        b = o;
        return;
    }
    o->push();
    int leftSize = 0;
    if(o->l) leftSize = o->l->sz;
    if(leftSize + 1 <= R){
        a = o;
        Split(o->r, a->r, b, R - leftSize - 1);
        a->pull();
    } else {
        b = o;
        Split(o->l, a, b->l, R);
        b->pull();
    }
}

void print(Node *n){
    n->push();
    if(n->l) print(n->l);
    cout << n->v << endl;
    if(n->r) print(n->r);
}

lld n, m, a, b;
Node *w, *x, *y, *z;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    root = new Node(1);
    for(int i = 2; i <= n; i++){
        root = Merge(root, new Node(i));
    }
    while(m--){
        cin >> a >> b;
        w = x = y = z = NULL;
        Split(root, w, x, b);
        Split(w, y, z, a - 1);
        z->f = !(z->f);
        root = Merge(y, Merge(x, z));
    }
    print(root);
}
