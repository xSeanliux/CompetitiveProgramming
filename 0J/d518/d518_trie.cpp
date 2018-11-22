#include <iostream>
#include <string.h>
using namespace std;

struct Node{
    string s;
    char c;
    int nChild;
    int number;
    Node *childs[30];
    bool isEnd;
};

int N;
string s;

void dfs(Node *currentNode){
    for(int i = 0; i < currentNode->nChild; i++){
        dfs(currentNode->childs[i]);
    }
    delete currentNode;
}

int main(){
    while(cin >> N){
        int currentIndex = 0;
        Node *root = new Node();
        //cout << root->s << endl;
        //cout << "hey" << endl;
        root->s = "";
        //cout << "hey" << endl;
        root->nChild = 0;
        //cout << "hey" << endl;
        root->isEnd = false;
        //cout << "hey" << endl;
        for(int i = 0 ; i < N; i++){
            cin >> s;
            int l = s.length();
            Node *currentNode = root;
            for(int j = 0 ; j < l ; j++){
                //cout << "Checking: " << s[j] << endl;
                for(int k = 0; k <= currentNode->nChild; k++){
                    //cout << currentNode->nChild << endl;
                    if(k >= currentNode->nChild){
                        //cout << "New" << endl;
                        Node *newNode = new Node();
                        //cout <<currentNode->s + s[j]<<endl;
                        newNode->s = currentNode->s + s[j];
                        //cout << "a" << endl;
                        newNode->c = s[j];
                        newNode->nChild = 0;
                        newNode->isEnd = 0;
                        //cout << "a" << endl;
                        currentNode->childs[currentNode->nChild] = newNode;
                        currentNode->nChild++;
                        currentNode = currentNode->childs[currentNode->nChild-1];
                        break;
                    } else if(currentNode->childs[k]->c == s[j]){
                        currentNode = currentNode->childs[k];
                        //cout << "Old" << endl;
                        break;
                    }
                }
                //cout << "a" << endl;
                //cout << "String: " << currentNode->s << endl;
                if(j == l-1){
                    if(currentNode->isEnd){
                        cout << "Old! " << currentNode->number << endl;
                    } else {
                        cout << "New! " << ++currentIndex << endl;
                        currentNode->number = currentIndex;
                        currentNode->isEnd = true;
                    }
                }
            }
        }
        dfs(root);
    }
}
