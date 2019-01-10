#include <iostream>
using namespace std;

int R = 7122;

int rand(){
    return R = (0xdefaced*R)%(1000000000 + 7) + 1;
}

struct Node{
    Node *l, *r;
    int key, pri;
    Node(int key): key(key), pri(rand()), l(NULL), r(NULL) //constructor
        {}
};

Node *nodeMerge(Node *a, Node *b){ //b key > a key
    if(!a || !b) return a ? a : b;
    if(a->pri < b->pri){
        a->r = nodeMerge(a->r, b);
        return a;
    } else {
        b->l = nodeMerge(b->l, a);
        return b;
    }
}

void nodeSplit(Node *o, Node *&a, Node *&b, int k){//put the nodes with value < k into a, and else into b
    if(!o) a = b = NULL;
    if(o->key < k){
        a = o; //a-> left is right but just need to sort out the right bit
        nodeSplit(o->r, a->r, b, k);
    } else {
        b = o;
        nodeSplit(o->l, a, b->l, k);
    }
}

void nodeInsert(Node *&root, int k){
    Node *a, *b;
    nodeSplit(root, a, b, k);
    root = nodeMerge(a, nodeMerge(new Node(k), b));
}

bool nodeErase(Node *&o, int k){
    if(!o) return false; //Node not found
    if(o->key == k){
        Node *t = o;
        o = nodeMerge(o->l, o->r);
        delete t;
        return true;
    }
    Node *&t = o->key < k ? o->l : o->r;
    return nodeErase(t, k);
}

int main(){

}
