#include <iostream>
using namespace std;

const int maxLog = 20;

struct Node{
    Node *chi[2];
    bool isFull;
    Node(){
        chi[0] = chi[1] = NULL;
        isFull = false;
    }
} *root;

int getBit(int x, int l){
    return ((1LL << (maxLog - l)) & x) > 0;
}

void Insert(Node *&cur, int val, int layer){
    int bit = getBit(val, layer);
    //cout << "Going " << bit << endl;
    if(!cur->chi[bit]){
        cur->chi[bit] = new Node();
    }
    if(layer == maxLog){
        cur->chi[bit]->isFull = true;
    } else {
        Insert(cur->chi[bit], val, layer + 1);
        //cout << val << ", layer = " << layer << ": ISFULL = " << cur->isFull << endl;
    }
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

int N, M, a, s = 0;


int main(){
    root = new Node();
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> a;
        Insert(root, a, 0);
    }
    while(M--){
        cin >> a;
        s ^= a;
        cout << query(root, s, 0) << endl;
    }
}
