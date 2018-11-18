#include <iostream>
using namespace std;



struct Node{
    int index;
    int head;
    bool visited = false;
    Node* parent;
    int first, second;
    Node *connected[10000];
    Node *anc[100];
} nodes[100];

int t = 0, a, b;

bool isAnc(Node *a, Node *b){
    return a->first <= b->first && a->second >= b->second;
}

void dfs(int node){
    //cout << node << " ";
    t++;
    nodes[node].first = t;
    //cout << "node " << node << " has " << nodes[node].head << " children" << endl;
    for(int i = 0 ; i < nodes[node].head; i++){
        nodes[node].visited = true;
        nodes[node].anc[0] = nodes[node].parent;
        Node *parent;
        //cout << "hey" << endl;
        if(node){
            for(int i = 1; i < 100; i++){
                parent = nodes[node].anc[i-1];
                nodes[node].anc[i] = parent->anc[i-1];
                //cout << "parent = " << parent->index << endl;
                //cout << "anc[" << i << "] = " <<nodes[node].anc[i]->index << endl;
                //cout << "ok with i = " << i << endl;
            }
        }
        //cout << "p" << endl;
        if(!nodes[node].connected[i]->visited){
            //cout << node <<  " has child " << nodes[node].connected[i]->index << endl;
            nodes[node].connected[i]->visited = true;
            nodes[node].connected[i]->parent = &nodes[node];
            dfs(nodes[node].connected[i]->index);
            nodes[node].connected[i]->visited = false;
            //cout << node << " ";
            t++;
        }
    }
    nodes[node].second = t;
    cout << node << ": " << nodes[node].first << ", " << nodes[node].second << endl;
}


int main(){
    nodes[0].parent = &nodes[0];
    for(int i = 0 ; i < 100; i++){
        nodes[i].index = i;
    }
    for(int i = 0 ; i < 100; i++){
        nodes[0].anc[i] = &nodes[0]; //root's ancestors are itself.
    }
    while(cin >> a >> b){
        if(a == b){ //run algorithm
            dfs(0);
            //cout << isAnc(&nodes[1], &nodes[5]);
            while(cin >> a >> b){ //LCA of A and B
                Node *A = &nodes[a];
                Node *B = &nodes[b];
                bool hasAns = false;
                //cout << "hey"<<endl;
                for(int i = 99; i >= 0 && !hasAns; i--){
                    cout << "i = " << i << ", anc: " << A->anc[i]->index<< endl;
                    if(isAnc(A, B)){
                        cout << A->index << endl;
                        hasAns = true;
                    } else if(isAnc(A->parent, B)){
                        cout << A->parent->index << endl;
                        hasAns = true;
                    } else if(!isAnc(A->anc[i] , B)){
                        A = A->anc[i];
                        cout << "A is now " << A->index << endl;
                        i = 99;
                    }
                }
                if(!hasAns)
                    cout << A->index << endl;
            }

        } else {
            nodes[a].connected[nodes[a].head] = &nodes[b];
            nodes[a].head++;
            //cout << "nodes[" << a << "] has " << nodes[a].head << " children" << endl;
            nodes[b].connected[nodes[b].head] = &nodes[a];
            nodes[b].head++;
            //cout << "nodes[" << b << "] has " << nodes[b].head << " children" << endl;

        }
    }
}


