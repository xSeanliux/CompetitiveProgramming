#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int l, r;
    long long int gcd;
    Node *L, *R;
};

long long int G(long long int a, long long int b){
    //if(a < b) swap(a, b);
    return (b == 0)? a : G(b, a % b);
}

long long int arr[100000 + 69];

long long int query(int l, int r, Node *N){
    //cout << "Running query of " << l << " to " << r << "." << endl;
    if(l == N->l && r == N->r){
        return N -> gcd;
    } else {
        int lim = (N->r+N->l)/2;
        if(l > lim && r > lim){ // on the right
            return query(l, r, N->R);
        } else if(l <= lim && r <= lim){ // on the left
            return query(l, r, N->L);
        } else { // on both sides
            return G(query(l, lim, N->L), query(lim + 1, r, N->R));
        }
    }
}


void update(Node *N, int I, long long int V){ //Node, Index, Value
    if(N->l == N-> r){
        N-> gcd = V;
        return;
    }
    int M = (N->l + N->r)/2;
    if(I <= M)
        update(N->L, I, V);
    if(I > M)
        update(N->R, I, V);

    N->gcd = G(N->L->gcd, N->R->gcd);
    return;
}

Node* buildTree(long long int l, long long int r){
    //cout << "Running f(" << l << ", " << r << ")" << endl;
    Node *n = new Node;
    n -> l = l;
    n -> r = r;
    if(l == r){
        n -> gcd = arr[l];
        n -> L = NULL;
        n -> R = NULL;
    } else {
        n -> L = buildTree(l, (r+l)/2);
        n -> R = buildTree((r+l)/2 + 1, r);
        n -> gcd = G(n -> L -> gcd, n -> R -> gcd);
    }
    return n;
}

long long int N, Q, a, b;
char C;


int main(){
    cin >> N >> Q;
    for(int i = 1 ; i <= N; i++){
        cin >> arr[i];
    }
    Node *root = buildTree(1, N+1);
    for(int i = 0 ; i < Q; i++){
        cin >> C >> a >> b;
        if(C == 'q'){
            cout << query(a, b, root) << endl;
        } else if(C == 'm'){
            update(root, a, b);
        }
    }
}
