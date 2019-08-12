#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    bool isEnd;
    Node *left, *right;
    Node(){
        isEnd = false;
        left = NULL;
        right = NULL;
    }
} *root, *currentNode;

bool isOk;
string s;
int C = 0;

void deleteTree(Node *root){
    if(root->left){
        deleteTree(root->left);
    }
    if(root->right){
        deleteTree(root->right);
    }
    delete root;
}

int main(){
    isOk = true;
    root = new Node();
    while(cin >> s){
        if(s == "9"){
            if(isOk){
                printf("Set %d is immediately decodable\n", ++C);
            } else {
                printf("Set %d is not immediately decodable\n", ++C);
            }
            isOk = true;
            //deleteTree(root);
            root = new Node();
        } else {
            if(isOk){
                currentNode = root;
                for(int i = 0; i < s.length(); i++){
                    if(s[i] == '0'){
                        //printf("Going left\n");
                        if(!currentNode->left){
                            currentNode->left = new Node();
                        }
                        currentNode = currentNode->left;
                    } else {
                        //printf("Going right\n");
                        if(!currentNode->right){
                            currentNode->right = new Node();
                        }
                        currentNode = currentNode->right;
                    }
                    if(currentNode->isEnd){
                        isOk = false;
                        break;
                    }
                }
                currentNode->isEnd = true;
                if(currentNode->left || currentNode->right){
                    isOk = false;
                }
            }
        }
    }
}

