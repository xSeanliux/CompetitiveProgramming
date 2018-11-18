#include <iostream>
using namespace std;

char com;
int val;

struct Node{
    bool isEmpty;
    int n;
    Node *left;
    Node *right;
} *root;

Node* create(){
    Node *t = new Node();
    t -> isEmpty = true;
    t -> left = NULL;
    t -> right = NULL;
    return t;
}

void input(Node *currentNode, int k){
    if(currentNode -> isEmpty){
        currentNode -> isEmpty = false;
        currentNode -> n = k;
    } else if (currentNode -> n >= k){
        if(currentNode -> left == NULL)
            currentNode -> left = create();
        input(currentNode -> left, k);
    } else {
        if(currentNode -> right == NULL)
            currentNode -> right = create();
        input(currentNode -> right, k);
    }
}

bool findNode(Node *currentNode, int val){
    if(currentNode -> isEmpty || (currentNode -> left == NULL && currentNode -> right == NULL && currentNode -> n != val)) return false;
    if(currentNode -> n == val)
        return true;
    if(currentNode -> n >= val){
        return findNode(currentNode -> left, val);
    } else {
        return findNode(currentNode -> right, val);
    }
}

void output(Node *currentNode){
    if(currentNode == NULL) return;
    output(currentNode -> left);
    cout << currentNode -> n << " ";
    output(currentNode -> right);
}

int main(){
    root = create();
    while(cin >> com){
        if(com == 'a'){ //add
            cin >> val;
            input(root, val);
        } else if(com == 'b'){ //search
            cin >> val;
            cout << findNode(root, val);
        } else if(com == 'c') {
            output(root);
        } else {
            continue;
        }
    }
}
