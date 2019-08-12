#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int block_size = 100;
int totalSize = 0, x, k;
string str;
struct Node{
    int val;
    Node *prev, *next;
    Node(int val): val(val), prev(NULL), next(NULL){}
    Node(int val, Node *prev, Node *next): val(val), prev(prev), next(next){}
};

struct Block{
    Node *s, *e;
    int sz;
    Block(): s(NULL), e(NULL), sz(0){}
    Block(Node *n): s(n), e(n), sz(1){}
    Node *popb(){
        Node *n = e;
        if(s == e){
            s = NULL;
            e = NULL;
        } else {
            e = e->prev;
            e->next = NULL;
        }
        sz--;
        return n;
    }
    Node *popf(){
        Node *n = s;
        if(s == e){
            s = NULL;
            e = NULL;
        } else {
            s = s->next;
            s->prev = NULL;
        }
        sz--;
        return n;
    }
    void *pushb(Node *n){
        if(s == NULL && e == NULL){
            n->prev = n->next = NULL;
            s = n;
            e = n;
        } else {
            n->next = NULL;
            e->next = n;
            n->prev = e;
            e = n;
        }
        sz++;
    }
    void pushf(Node *n){
        if(s == NULL && e == NULL){
            n->prev = n->next = NULL;
            s = n;
            e = n;
        } else {
            n->prev = NULL;
            s->prev = n;
            n->next = s;
            s = n;
        }
        sz++;
    }
    void display(){
        Node *n = s;
        while(n){
            cout << n->val << " ";
            n = n->next;
        }
    }
} blocks[100000/block_size + 10];

void Insert(int x, int k){
    //block No. (k - 1) / block_size, (k - 1) % block_size th in the block;
    int cnt = 0;
    if((k - 1) % block_size == 0){
        blocks[(k - 1) / block_size].pushf(new Node(x));
        int currentBlock = (k - 1) / block_size;
        while(blocks[currentBlock].sz > block_size){
            currentBlock++;
            blocks[currentBlock].pushf(blocks[currentBlock-1].popb());
        }
        return;
    }
    if(blocks[(k - 1) / block_size].sz == (k - 1) % block_size){
        //cout << "AAY" << endl;
        blocks[(k - 1) / block_size].pushb(new Node(x));
        int currentBlock = (k - 1) / block_size;
        while(blocks[currentBlock].sz > block_size){
            currentBlock++;
            blocks[currentBlock].pushf(blocks[currentBlock-1].popb());
        }
        return;
    }
    Node *n = blocks[(k - 1) / block_size].s;
    for(int i = 0; i < ((k - 1) % block_size); i++){
        n = n->next;
    }
    Node *s = new Node(x);
    s->next = n;
    s->prev = n->prev;
    if(n->prev)
        n->prev->next = s;
    n->prev = s;
    int currentBlock = (k - 1) / block_size;
    blocks[(k - 1) / block_size].sz++;
    //cout << "SZ = " << blocks[(k - 1) / block_size].sz << endl;
    while(blocks[currentBlock].sz > block_size){
        //cout << "NOP" << endl;
        currentBlock++;
        blocks[currentBlock].pushf(blocks[currentBlock-1].popb());
    }
}

void Delete(int k){
    if((k - 1) % block_size == blocks[(k - 1) / block_size].sz - 1){
        blocks[(k - 1) / block_size].popb();
        int currentBlock = (k - 1) / block_size;
        while(blocks[currentBlock].sz < block_size && blocks[currentBlock + 1].sz > 0){
            blocks[currentBlock].pushb(blocks[currentBlock + 1].popf());
            currentBlock++;
        }
        return;
    }
    if((k - 1) % block_size == 0){
        blocks[(k - 1) / block_size].popf();
        int currentBlock = (k - 1) / block_size;
        //cout << "Y" << endl;
        while(blocks[currentBlock].sz < block_size && blocks[currentBlock + 1].sz > 0){
            blocks[currentBlock].pushb(blocks[currentBlock + 1].popf());
            currentBlock++;
        }
        return;
    }
    Node *n = blocks[(k - 1) / block_size].s;
    for(int i = 0; i < (k - 1) % block_size; i++){
        n = n->next;
    }
    //cout << "Deleting element with alue" << n->val << endl;
    if(n->next){
        n->next->prev = n->prev;
    } else {
        blocks[(k - 1) / block_size].e = n;
    }
    if(n->prev){
        n->prev->next = n->next;
    } else {
        blocks[(k - 1) / block_size].s = n;
    }
    blocks[(k - 1) / block_size].sz--;
    int currentBlock = (k - 1) / block_size;
    while(blocks[currentBlock].sz < block_size && blocks[currentBlock + 1].sz > 0){
        blocks[currentBlock].pushb(blocks[currentBlock + 1].popf());
        currentBlock++;
    }
}

void getkth(int k){
    Node *n = blocks[(k - 1) / block_size].s;
    for(int i = 0; i < (k - 1) % block_size; i++){
        n = n->next;
    }
    cout << n->val << endl;
    return;
}

int N, M;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i <= M/block_size + 1; i++){
        blocks[i] = Block();
    }
    for(int i = 1; i <= N; i++){
        cin >> x;
        Insert(x, i);
        //cout << "i = " << i << endl;
    }
    for(int i = 0; i < M; i++){
        cin >> str;
        if(str == "ADD"){
            cin >> k >> x;
            Insert(x, k);
        } else {
            cin >> k;
            if(str == "LEAVE"){
                Delete(k);
            } else {
                getkth(k);
            }
        }
    }

}
