#include <iostream>
using namespace std;

int com, currentPos, vals[1000], minPos, maxPos, c = 1;

struct Node{
    int n;
    int xpos;
    Node *parent;
    Node *left;
    Node *right;
} *root;

Node *nodeStack[1000];
int head = 1;

Node *create(){
    Node *t = new Node();
    t -> left = NULL;
    t -> right = NULL;
    //t -> parent = NULL;
    t -> n = 0;
    t -> xpos = 0;
    return t;
}

bool isFinished(Node *currentNode){
    if(currentNode -> left == NULL || currentNode -> right == NULL ) {
        if(currentNode -> n == -1) return true;
        return false;
    }
    else return (isFinished(currentNode -> left) && isFinished(currentNode -> right));
}

Node *findNextCanGo(Node *currentNode){
    if(currentNode -> n == -1) return NULL;
    if(currentNode -> n == 0) return currentNode;
    if(currentNode -> left == NULL) currentNode -> left = create();
    if(currentNode -> right == NULL) currentNode -> right = create();
    Node *leftRes = findNextCanGo(currentNode -> left);
    Node *rightRes = findNextCanGo(currentNode -> right);
    if(leftRes != NULL) {
        //cout << "Choose lft" << endl;
        currentPos--;
        return leftRes;
    }
    if(rightRes != NULL) {
        //cout << "Choose right" << endl;
        currentPos++;
        return rightRes;
    }
    //if(rightRes != NULL) return rightRes;
    return NULL;
}

int main(){
    root = create();
    nodeStack[0] = root;
    head = 1;
    maxPos = minPos = 50;
    while(cin >> com){
            if(root -> n == 0){
                if(com == -1) return 0;
                root -> n = com;
                vals[50] += com;
                continue;
            }
            Node *currentNode = root;
            currentPos = 0;
            Node *canGo = findNextCanGo(root);
            canGo -> n = com;
            //printf("max: %d, min: %d\n", maxPos - 50, minPos - 50);
            //cout << "Position of" << com << " is: " << currentPos << endl;
            if(com != -1){
                vals[currentPos + 50] += com;
                //printf("vals[%d] += %d\n", currentPos + 50, com);
                if(currentPos + 50 > maxPos) maxPos = currentPos + 50;
                if(currentPos + 50 < minPos) minPos = currentPos + 50;
            }

            if(isFinished(root)){//calculate
                //more calculations + output
                //if(c-1)
                  //  cout << endl;

                cout << "Case " << c << ":" << endl;
                for(int i = minPos; i <= maxPos; i++){
                    cout << vals[i];
                    if(i < maxPos) cout << " ";
                    vals[i] = 0;
                }
                //cout << vals[maxPos];
                cout << endl << endl;
                //cout << "FINISHED!"<<endl;
                root = create();
                c++;
                maxPos = minPos = 50;
                //input the com as well lol
            }

    }
}
