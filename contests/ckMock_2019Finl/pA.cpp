#include <iostream>
using namespace std;

const int maxN = 30;

struct Node{
    Node *z, *o;
    int sz;
    Node(): sz(0), z(NULL), o(NULL){}
    Node(Node *zN, Node *oN): z(zN), o(oN){
        pull();
    }
    void pull(){
        sz = 0;
        if(z) sz += z->sz;
        if(o) sz += o->sz;
    }
} *root;

bool isOne(int x, int k){
    return (((1LL << (maxN - k)) & x) > 0);
}

void Ins(Node *&root, int x, int lay = 0){
    if(lay > maxN){
        root->sz++;
        return;
    }
    if(isOne(x, lay)){
        if(!root->o) root->o = new Node();
        Ins(root->o, x, lay + 1);
    } else {
        if(!root->z) root->z = new Node();
        Ins(root->z, x, lay + 1);
    }
    root->pull();
}

void Del(Node *&root, int x, int lay = 0){
    if(lay > maxN){
        root->sz--;
        return;
    }
    if(isOne(x, lay)){
        Del(root->o, x, lay + 1);
        if(!root->o->sz) delete root->o;
    } else {
        Del(root->z, x, lay + 1);
        if(!root->z->sz) delete root->z;
    }
    root->pull();
}

int getMax(Node *root, int x, int lay = 0){
    if(lay > maxN) return 0;
    if(isOne(x, lay)){
        if(root->z) return (1 << (30 - lay)) + getMax(root->z, x, lay + 1);
        else return getMax(root->o, x, lay + 1);
    } else {
        if(root->o) return (1 << (30 - lay)) + getMax(root->o, x, lay + 1);
        else return getMax(root->z, x, lay + 1);
    }
}

int main(){
    root = new Node();
    Ins(root, 0);

}
