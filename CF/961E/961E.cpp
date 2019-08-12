#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

vector<int> vec;

struct Node{
    Node *l, *r;
    vector<int> arr;
    Node(int x): l(NULL), r(NULL), arr(1, x){}
    Node(Node *l, Node *r): l(l), r(r), arr(){
        pull();
    }
    void pull(){
        arr.clear();
        arr.resize(l->arr.size() + r->arr.size());
        merge(l->arr.begin(), l->arr.end(), r->arr.begin(), r->arr.end(), arr.begin());
    }
} *root;

int N, x;

Node* build(int l, int r){
    //cout << "Building (" << l << ", " << r << ")" << endl;
    if(l + 1 == r){
        return new Node(vec[l]);
    } else {
        return new Node(build(l, r + l >> 1), build(r + l >> 1, r));
    }
}

int howmanyLarger(Node *n, int ql, int qr, int l, int r, int k){
    //cout << "Running (" << ql << ", " << qr << "), (" << l << ", " << r << ")" << endl;
    if(qr <= l || ql >= r) return 0;
    else if(ql <= l && r <= qr){
        /*
        cout << "QUERY: " << k << " ARR: ";
        for(int i : n->arr){
            cout << i << " ";
        }
        cout << "ANS = " << n->arr.size() - (lower_bound(n->arr.begin(), n->arr.end(), k) - n->arr.begin()) << endl;
        cout << endl;
        */
        return n->arr.size() - (lower_bound(n->arr.begin(), n->arr.end(), k) - n->arr.begin());
    } else {
        int z = (howmanyLarger(n->l, ql, qr, l, l + r >> 1, k) + howmanyLarger(n->r, ql, qr, l + r >> 1, r, k));
        //cout << "ANS FOR (" << ql << ", " << qr << "), (" << l << ", " << r << ") is " << z << endl;
        return z;
    }
}

signed main(){
    cin >> N;
    vec.resize(N + 2);
    for(int i = 1; i <= N; i++){
        cin >> vec[i];
    }
    root = build(1, N + 1);
    int ans = 0;
    for(int i = 1; i <= N; i++){
        int k = howmanyLarger(root, 1, min(N, vec[i]) + 1, 1, N + 1, i);
        //cout << "Running query from 1 to " << min(N, vec[i]) + 1 << endl;
        ans += k - (i <= vec[i]);
        //cout << "There are " << k << " numbers >= " << i << " in the range[" << 1 << ", " << min(N, vec[i]) + 1<< "]" << endl;
    }
    cout << (ans)/2 << endl;
}
