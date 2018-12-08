#include <iostream>
#include <vector>
#include <string>
using namespace std;
int nBlocks, arg1, arg2, currentPos[50];
string s1, s2;


class Node{
public:
    int val;
    Node *next;
    Node(int v){
        this->val = v;
        this->next = NULL;
    }
    Node(int v, Node *n){
        this->val = v;
        this->next = n;
    }
} *tape[100];



Node *getNode(int a){
    int pos = currentPos[a];
    Node *n = tape[pos];
    while(n->next && n->next->val != a) {n = n->next;}
    return  n->next;
}

Node *getAncestor(int a){
    int pos = currentPos[a];
    Node *n = tape[pos];
    while(n->next && n->next->val != a) {n = n->next;}
    return n;
}

void returnAbove(Node *a){
    if(a->next) a = a->next;
    else return;
    while(a){
        if(a->next){
            Node *n = a->next;
            tape[a->val]->next = a;
            tape[a->val]->next->next = NULL;
            currentPos[a->val] = a->val;
            //cout << "Returned " << a->val << endl;
            a = n;
        } else {
            tape[a->val]->next = a;
            tape[a->val]->next->next = NULL;
            currentPos[a->val] = a->val;
            //cout << "Returned " << a->val << endl;
            break;
        }

    }
}


void moveOnto(int x, int y){
    //move the blocks above a to the init places
    Node *a = getNode(x);
    Node *b = getNode(y);
    returnAbove(a);
    returnAbove(b);
    a = getNode(x);
    b = getNode(y);
    Node *ances = getAncestor(x);
    ances->next = NULL;
    b->next = a;
    a->next =NULL;
    currentPos[x] = currentPos[y];
}

void moveOver(int x, int y){
    Node *a = getNode(x);
    Node *b = getNode(y);
    returnAbove(a);
    while(b->next){
        b = b->next;
    }
    Node *ances = getAncestor(x);
    ances->next = NULL;
    b->next = a;
    a->next = NULL;
    currentPos[x] = currentPos[y];
}

void pileOnto(int x, int y){
    Node *a = getNode(x);
    Node *b = getNode(y);
    Node *ances = getAncestor(x);
    ances->next = NULL;
    returnAbove(b);
    b->next = a;
    Node *k = b->next;
    while(k){
        currentPos[k->val] = currentPos[y];
        if(k->next)
            k = k->next;
        else break;
    }

}

void pileOver(int x, int y){
    Node *a = getNode(x);
    Node *b = getNode(y);
    while(b->next) b = b->next;
    Node *ances = getAncestor(x);
    ances->next = NULL;
    b->next = a;
    Node *k = b->next;
    while(k){
        currentPos[k->val] = currentPos[y];
        if(k->next)
            k = k->next;
        else break;
    }
}

int main(){
    cin >> nBlocks;
    for(int i = 0; i < nBlocks; i++){
        Node *starter = new Node(i), *root = new Node(-1);
        tape[i] = root;
        tape[i]->next = starter;
        currentPos[i] = i;
    }
    while(cin >> s1){
        if(s1 == "quit"){
            for(int i = 0; i < nBlocks; i++){
                cout << i << ":";
                Node *n = tape[i];
                while(n){
                    if(n->val != -1)
                        cout << " " << n->val;
                    if(n->next)
                        n = n->next;
                    else
                        break;
                }
                cout << endl;
            }
            break;
        } else{
            cin >> arg1 >> s2 >> arg2;
            if(currentPos[arg1] == currentPos[arg2]) continue;
            if(s1 == "move" && s2 == "onto"){
                moveOnto(arg1, arg2);
            } else if(s1 == "move" && s2 == "over"){
                moveOver(arg1, arg2);
            } else if(s1 == "pile" && s2 == "onto"){
                pileOnto(arg1, arg2);
            } else if(s1 == "pile" && s2 == "over"){
                pileOver(arg1, arg2);
            }
            /*
            for(int i = 0; i < nBlocks; i++){
                cout << i << ":";
                Node *n = tape[i];
                while(n){
                    if(n->val != -1)
                        cout << " " << n->val;
                    if(n->next)
                        n = n->next;
                    else
                        break;
                }
                cout << endl;
            }
            cout << endl;
            for(int i = 0 ; i < nBlocks; i++){
                cout << currentPos[i] << " ";
            }
            cout << endl;
            */
        }
    }




}
