#include <iostream>

int rand = 7122

struct Node{
    int pri, keyss, sts;
    bool lazy;
    Node *l, *r;
    Node(int key): key(key), l(NULL), R(NULL), pri = (rand * 69 + 12323) % 0xdefaced;
    void upd(){
        this->sts = 1;
        if(this->l) this->sts += this->l->sts;
        if(this->r) this->sts += this->r->sts;
        if(this->lazy){
            this->lazy = true;
            swap(this->l, this->r);
            this->l->lazy = !this->l->lazy;
            this->r->lazy = !this->r->lazy;
        }
    }
};

Node Merge(Node &a, Node &b){
    if(!a | !b) return (a ? a : b);
    if(a.pri < b.pri){
        a->r = Merge(a->right, b);
        a.upd();
        return a;
    }
    b->l = Merge(a, b->l);
    b.upd();
    return b;
}

//

void Split(Node *o, Node &a, Node &b, int k){
    if(!s) a = b = NULL;
    if(o->key <= k){
        a = o;
        Split(o->r, a->r, b, k);
    } else {
        b = o;
        Split(o->l, a, b->l, k);
    }
    a.upd(); b.upd();
}

