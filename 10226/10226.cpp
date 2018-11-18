#include <iostream>
#include <string.h>
using namespace std;

int cases, cc, nTrees;
string command;

struct TreeName{
    string name;
    int amount;
    bool isEmpty;
    TreeName *left;
    TreeName *right;
} *root;

TreeName* create(){
    TreeName *t = new TreeName();
    t -> name = "";
    t -> amount = 0;
    t -> isEmpty = true;
    t -> left = t -> right = NULL;
    return t;
}

void input(TreeName *currentNode, string query){
    if(!((currentNode -> name).compare(query))){
        currentNode -> amount++;
        //cout << currentNode -> name << "++" << endl;
    } else if(currentNode -> isEmpty){
        currentNode -> isEmpty = false;
        currentNode -> name = query;
        currentNode -> amount = 1;
        //cout << "New: " << currentNode -> name << endl;
    } else if((currentNode -> name).compare(query) > 0){
        if(currentNode -> left == NULL)
            currentNode -> left = create();
        input(currentNode -> left, query);
    } else {
        if(currentNode -> right == NULL)
            currentNode -> right = create();
        input(currentNode -> right, query);
    }
}

void findNames(TreeName *currentNode){
    if(currentNode == NULL) return;
    findNames(currentNode -> left);
    cout << currentNode -> name;
    printf(" %.4f\n", 100.0 * currentNode -> amount / nTrees);
    findNames(currentNode -> right);
}

int main(){
    cin >> cases;
    cc = 0;
    root = create();
    getline(cin, command);
    getline(cin, command);
    for(int i = 0 ; i < cases; i++){
        while(getline(cin, command)){
            //cout << command << endl;
            if(command == ""){
                    //cout << "YO" << endl;
                    findNames(root);
                    cout << endl;
                    root = create();
                    nTrees = 0;
                    continue;
            }
            input(root, command);
            nTrees++;
        }
    }
    findNames(root);
}
