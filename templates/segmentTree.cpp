#include <iostream>
using namespace std;

struct Node{
    int left;
    int right;
    int maxVal;
    int sum;
    Node *leftNode;
    Node *rightNode;
};

int N, arr[1000];

Node* buildTree(int left, int right){
    Node* n = new Node();
    n->left = left;
    n->right = right;
    if(left == right){
        n->sum = arr[left];
        n->maxVal = arr[left];
        n->leftNode = NULL;
        n->rightNode = NULL;
    } else {
        n->leftNode = buildTree(left, left + (right - left)/2);
        n->rightNode = buildTree(left + (right - left)/2 + 1, right);
        n->sum = n->leftNode->sum + n->rightNode->sum;
        n->maxVal = max(n->leftNode->maxVal, n->rightNode->maxVal);
    }
    return n;
}

int getSum(Node *n, int left, int right){
    cout << "Sum(" << left << ", " << right << ")" << endl;
    if(n->left == left && n->right == right){
        return n->sum;
    } else {
        int ans = 0, mid = n->left + (n->right - n->left)/2 + 1;
        if(left < mid){
            ans += getSum(n->leftNode, left, min(right, mid-1));
        }
        if(right >= mid){
            ans += getSum(n->rightNode, max(left, mid), right);
        }
        return ans;
    }
}

void add(Node *n, int ind, int val){
    if(n->left == ind && n->right == ind){
        n->sum += val;
        n->maxVal = n->sum;
    } else {
        int mid = mid = n->left + (n->right - n->left)/2 + 1;
        if(ind < mid){
            add(n->leftNode, ind, val);
        } else
            add(n->rightNode, ind, val);
        n->sum = n->leftNode->sum + n->rightNode->sum;
        n->maxVal = max(n->leftNode->maxVal, n->rightNode->maxVal);
    }
}

int getInd(Node *n, int ind){
    if(n->left == ind && n->right == ind){
        return n->sum;
    } else {
        int mid = n->left + (n->right - n->left)/2 + 1;
        if(ind < mid){
            return getInd(n->leftNode, ind);
        } else
            return getInd(n->rightNode, ind);
    }
}

int getMax(Node* n, int left, int right){
    if(n->left == left && n->right == right){
        return n->maxVal;
    }
    int mid = n->left + (n->right - n->left)/2 + 1, ans = 0;
    if(left < mid)
        ans = max(ans, getMax(n->leftNode, left, min(mid-1, right)));
    if(right >= mid)
        ans = max(ans, getMax(n->rightNode, max(mid, left), right));
    return ans;
}

void mod(Node *n, int left, int right, int M){
    if(n->maxVal < M) return;
    if(left == right){
        n->sum %= M;
        n->maxVal %= M;
    } else {
        int mid = n->left + (n->right - n->left)/2 + 1;
        if(left < mid)
            mod(n->leftNode, left, min(mid-1, right), M);
        if(right >= mid)
            mod(n->rightNode, max(mid, left), right, M);
        n->sum = n->leftNode->sum + n->rightNode->sum;
        n->maxVal = max(n->leftNode->maxVal, n->rightNode->maxVal);
    }
    return;
}

int a, b, c;
char com;

int main(){
    while(cin >> N){
        for(int i = 0 ; i < N; i++)
            cin >> arr[i];
        Node *root = buildTree(0, N-1);
        while(cin >> com){
            if(com == 'a'){
                cin >> a >> b;
                add(root, a, b);
            } else if(com == 's'){
                cin >> a >> b;
                cout << getSum(root, a, b) << endl;
            } else if(com == 'g'){
                cin >> a;
                cout << getInd(root, a) << endl;
            } else if(com == 'M'){
                cin >> a >> b;
                cout << getMax(root, a, b) << endl;
            } else if(com == 'm'){
                cin >> a >> b >> c;
                mod(root, a, b, c);
            }
        }
    }
}
