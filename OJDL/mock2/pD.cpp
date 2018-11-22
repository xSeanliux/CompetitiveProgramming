#include <iostream>
using namespace std;

struct Node{
    int sum;
    int minNum;
    int minIndex;
    int left;
    int right;
    Node *lNode;
    Node *rNode;
};

int N, Q, arr[1000006];

Node root;

Node getTree(int left, int right){
    cout << "Running getTree(" << left << ", " << right << ")" << endl;
    Node n;
    n.left = left;
    n.right = right;
    if(n.left == n.right){
        n.sum = arr[left];
        n.minNum = arr[right];
        n.rNode = n.lNode = NULL;
        n.minIndex = left;
        return n;
    } else {
        Node l = getTree(left, left + (right - left)/2);
        Node r = getTree(left + (right - left)/2 + 1, right);
        n.sum = l.sum + r.sum;
        n.minNum = min(l.minNum, r.minNum);
        if(l.minNum < r.minNum)
            n.minIndex = l.minIndex;
        else
            n.minIndex = r.minIndex;
        n.lNode = &l;
        n.rNode = &r;
        return n;
    }
}

void modifyAdd(Node *n, int k){
    cout << "Modifying: " << n->left << " to " << n->right << endl;
    //do things here
    if(left == right){
        n->sum += k;
        n->minNum += k;
        return;
    } else {
        int m = (n->right + n->left) / 2;
        cout << "m = " << m << endl;
        if(n->right < m){
            modifyAdd(n->lNode, k);
        } else if(n->left > m){
            modifyAdd(n->rNode, k);
        } else {
            modifyAdd(n->lNode, k);
            modifyAdd(n->rNode, k);
        }
    }
    //update the tree
    n->sum = n->lNode->sum + n->rNode->sum;
    n->minNum = min(n->lNode->minNum, n->rNode->minNum);
    if(n->lNode->minNum < n->rNode->minNum)
            n->minIndex = n->lNode->minIndex;
        else
            n->minIndex = n->rNode->minIndex;
}




int main(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    Node root = getTree(0, N);
    cout << root.minIndex << endl;
    modifyAdd(&root, 2);
    cout << "Min is at " << root.minIndex << endl;
}
