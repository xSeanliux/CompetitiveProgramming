#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int N, Q, arr[100006];
string s;

struct Node{
    int left;
    int right;
    int sum;
    Node *leftNode;
    Node *rightNode;
};

Node* buildNode(int left, int right){
    Node *root = new Node();
    root->left = left;
    root->right = right;
    if(left == right){
        root->sum = arr[left];
        root->leftNode = NULL;
        root->rightNode = NULL;
    } else {
        int mid = (left + right)/2;
        Node *lNode = buildNode(left, mid);
        Node *rNode = buildNode(mid + 1, right);
        root->leftNode = lNode;
        root->rightNode = rNode;
        root->sum = lNode->sum + rNode->sum;
    }
    //cout << "[" << left << ", " << right << "] = " << root->sum << endl;
    return root;
}

int getSum(int left, int right, Node *c){
    //cout << "Running sum [" << left << ", " << right << "]" << endl;
    if(c->left == left && c->right == right) {
        //cout << "Sum of[" << left << ", " << right << "] = " << c->sum << endl;
        return c->sum;
    }
    int mid = (c->left + c->right)/2, ans = 0;
    if(left <= mid)
        ans += getSum(left, min(right, mid), c->leftNode);
    if(right > mid)
        ans += getSum(max(left, mid+1), right, c->rightNode);
    //cout << "Sum of [" << left << ", " << right << "] = " << ans << endl;
    return ans;

}

int main(){
    cin >> N >> Q >> s;
    for(int i = 0 ; i < s.length(); i++)
        arr[i+1] = s[i] - '0';
    Node *n = buildNode(1, N);
    //cout << "done" << endl;
    int l, r;
    for(int i = 0 ; i < Q; i++){
        cin >> l >> r;
        int K = (r - l);
        int ones = getSum(l, r, n), zeroes = (r-l+1)-ones;
        //cout << "K = " << K << endl;
        int ans = 0;
        ans += (ones-1)*(ones)*(ones+1)/6;
        ans +=
        //cout << ""
        cout << K + getSum(l, r, n) << endl;
    }
}
