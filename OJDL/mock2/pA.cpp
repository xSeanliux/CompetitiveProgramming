#include <iostream>
using namespace std;

struct Node{
    int left;
    int right;
    long long int maxVal;
    long long int sum;
    Node *leftNode;
    Node *rightNode;
};

int arr[1000069];

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

long long int getSum(Node *n, long long int left, long long int right){
    if(n->left == left && n->right == right){
        return n->sum;
    } else {
        long long int ans = 0, mid = n->left + (n->right - n->left)/2 + 1;
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

void mod(Node *n, int left, int right, long long int M){
    //cout << "mod(" << left << ", " << right << ")" << endl;
    if(n->maxVal < M) return;
    if(n->left == n->right){
        n->sum %= M;
        n->maxVal = n->sum;
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

long long int N, q, a, b, c, d;
char com;

int main(){
    /*
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
    */
    cin >> N >> q;
    for(int i = 0 ; i < N; i++)
        cin >> arr[i];
    Node *root = buildTree(0, N-1);
    for(int i = 0 ; i < q; i++){
        cin >> a;
        if(a == 1){
            cin >> b >> c >> d;
            mod(root, b, c, d);
        } else if(a == 2){
            cin >> b >> c;
            cout << getSum(root, b, c) << endl;
        }
    }
}
