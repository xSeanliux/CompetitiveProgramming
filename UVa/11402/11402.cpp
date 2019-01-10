#include <iostream>
#include <string.h>
using namespace std;
//too naive - need to use lazy propogations

int T, M, N, Q, a, b, C = 0;
char c;
string s, all;


struct Node{
    int E, F, status; //E-Barbary(0); F:Buccaneer(1)
    Node *l, *r;
    Node(Node *l, Node *r): l(l), r(r), E(0), F(0)
        {
            this->E = this->l->E + this->r->E;
            this->F = this->l->F + this->r->F;
        }
    Node(int E, int F): E(E), F(F), l(NULL), r(NULL)
        {}

};

Node *buildTree(int l, int r){
    if(l == r) return (all[l] == '0') ? new Node(1, 0) : new Node(0, 1);
    int mid = (l + r)/2;
    //cout << "From " <<l << " to " <<r << ": (E, F) = (#0, #1) = " << n->E << ", " << n->F << endl;
    return new Node(buildTree(l, mid), buildTree(mid + 1, r));
}

int query(Node *o, int l, int r, int ql, int qr){
    if(r < ql || l > qr) return 0;
    if(l >= ql && r <= qr) return o->F;
    int mid = (l + r)/2;
    return query(o->l, l, mid, ql, qr) + query(o->r, mid + 1, r, ql, qr);
}

void switchToE(Node *o, int l, int r, int ql,  int qr){
    if(r < ql || l > qr) return;
    if(l == r){
        o->E = 1;
        o->F = 0;
    }  else {
        int mid = (l + r)/2;
        switchToE(o->l, l, mid, ql, qr);
        switchToE(o->r, mid + 1, r, ql, qr);
        o->E = o->l->E + o->r->E;
        o->F = o->l->F + o->r->F;
    }
}

void switchToF(Node *o, int l, int r, int ql,  int qr){
    if(r < ql || l > qr) return;
    if(l == r){
        o->E = 0;
        o->F = 1;
    }  else {
        int mid = (l + r)/2;
        switchToF(o->l, l, mid, ql, qr);
        switchToF(o->r, mid + 1, r, ql, qr);
        o->E = o->l->E + o->r->E;
        o->F = o->l->F + o->r->F;
    }
}

void flip(Node *o, int l, int r, int ql,  int qr){
    if(r < ql || l > qr) return;
    if(l == r){
        if(o->E){
            o->E = 0;
            o->F = 1;
        } else {
            o->E = 1;
            o->F = 0;
        }
    }  else {
        int mid = (l + r)/2;
        flip(o->l, l, mid, ql, qr);
        flip(o->r, mid + 1, r, ql, qr);
        o->E = o->l->E + o->r->E;
        o->F = o->l->F + o->r->F;
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> M;
        all = "";
        for(int i = 0; i < M; i++){
            scanf("%d", &N);
            while(N--)
                all += s;
        }
        //cout << all << endl;
        Node *root = buildTree(0, all.length() - 1);
        printf("Case %d:\n", ++C);
        int currentQuery = 0;
        cin >> Q;
        while(Q--){
            scanf("%c%d%d", &c, &a, &b);
            if(c == 'F'){
                switchToF(root, 0, all.length()-1, a, b);
            } else if(c == 'E'){
                switchToE(root, 0, all.length()-1, a, b);
            } else if(c == 'I'){
                flip(root, 0, all.length()-1, a, b);
            } else {
                printf("Q%d: %d\n", ++currentQuery, query(root, 0, all.length()-1, a, b));
            }
        }
    }
}
