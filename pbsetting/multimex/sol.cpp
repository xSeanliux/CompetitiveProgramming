#include <iostream>
using namespace std;

const int maxLog = 20;

struct Node{
    Node *chi[2];
    bool isFull;
    int sz;
    Node(){
        chi[0] = chi[1] = NULL;
        isFull = false;
        sz = 0;
    }
} *root;

int getBit(int x, int l){
    return ((1LL << (maxLog - l)) & x) > 0;
}

void Remove(Node *&cur, int val, int layer){
    int bit = getBit(val, layer);
    cur->chi[bit]->sz--;
    if(layer < maxLog){
        Remove(cur->chi[bit], val, layer + 1);
    }
    if(!cur->chi[bit]->sz){
        delete cur->chi[bit];
        cur->chi[bit] = NULL;
    }
    cur->sz = (cur->chi[0] ? cur->chi[0]->sz : 0) + (cur->chi[1] ? cur->chi[1]->sz : 0);
    cur->isFull = (cur->chi[0] && cur->chi[0]->isFull) && (cur->chi[1] && cur->chi[1]->isFull);
}

void Insert(Node *&cur, int val, int layer){
    int bit = getBit(val, layer);
    //cout << "Going " << bit << endl;
    if(!cur->chi[bit]){
        cur->chi[bit] = new Node();
    }
    if(layer == maxLog){
        cur->chi[bit]->isFull = true;
        cur->chi[bit]->sz++;
    } else {
        Insert(cur->chi[bit], val, layer + 1);
        //cout << val << ", layer = " << layer << ": ISFULL = " << cur->isFull << endl;
    }
    cur->sz = (cur->chi[0] ? cur->chi[0]->sz : 0) + (cur->chi[1] ? cur->chi[1]->sz : 0);
    cur->isFull = (cur->chi[0] && cur->chi[0]->isFull) && (cur->chi[1] && cur->chi[1]->isFull);
}

int query(Node *cur, int toxor, int layer){
    //cout << "Running query(" << toxor << ", " << layer << ")" << endl;
    if(!cur) return 0;
    int bit = getBit(toxor, layer);
    if(cur->chi[bit] && cur->chi[bit]->isFull){
        //cout << "Have to go other way" << endl;
        return (1LL << (maxLog - layer)) + query(cur->chi[bit ^ 1], toxor, layer + 1);
    } else {
        //cout << "Can go"<< endl;
        return query(cur->chi[bit], toxor, layer + 1);
    }
}

int N, M, c, a;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    root = new Node();
    cin >> N;
    while(N--){
        cin >> c;
        if(c == 1){
            cin >> a;
            Insert(root, a, 0);
        } else if(c == 2) {
            cin >> a;
            Remove(root, a, 0);
        } else if(c == 3) {
            cout << query(root, 0, 0) << endl;
        }
    }
}

