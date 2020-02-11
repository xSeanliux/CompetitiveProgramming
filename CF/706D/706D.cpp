#include <iostream>
#define int long long int
using namespace std;

struct Node{ //binary trie
    int cnt;
    Node *z, *o;
    Node(): cnt(0), z(NULL), o(NULL){}
} *root;

void ins(Node *currentNode, int x, int lvl){
    if(lvl == 31) return;
    if(x & (1LL << (30 - lvl))){
        if(!currentNode->o) currentNode->o = new Node();
        currentNode->o->cnt++;
        ins(currentNode->o, x, lvl + 1);
    } else {
        if(!currentNode->z) currentNode->z = new Node();
        currentNode->z->cnt++;
        ins(currentNode->z, x, lvl + 1);
    }
}

void rem(Node *currentNode, int x, int lvl){
    if(lvl == 31) return;
    if(x & (1LL << (30 - lvl))){
        currentNode->o->cnt--;
        rem(currentNode->o, x, lvl + 1);
        if(!(currentNode->o->cnt)){
            delete currentNode->o;
            currentNode->o = NULL;
        }
    } else {
        currentNode->z->cnt--;
        rem(currentNode->z, x, lvl + 1);
        if(!(currentNode->z->cnt)){
            delete currentNode->z;
            currentNode->z = NULL;
        }
    }
}

int query(Node *currentNode, int x, int lvl){
    if(lvl == 31) return 0;
    if(x & (1LL << (30 - lvl))){
        if(currentNode->z){
            return (1LL << (30 - lvl)) + query(currentNode->z, x, lvl + 1);
        } else {
            return query(currentNode->o, x, lvl + 1);
        }
    } else {
        if(currentNode->o){
            return (1LL << (30 - lvl)) + query(currentNode->o, x, lvl + 1);
        } else {
            return query(currentNode->z, x, lvl + 1);
        }
    }
}

int N, x;
char c;

signed main(){
    cin >> N;
    root = new Node();
    ins(root, 0, 0);
    while(N--){
        cin >> c >> x;
        if(c == '?'){
            cout << query(root, x, 0) << endl;
        } else if(c == '+'){
            ins(root, x, 0);
        } else if(c == '-'){
            rem(root, x, 0);
        }
    }
}
