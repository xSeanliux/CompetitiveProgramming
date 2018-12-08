#include <iostream>
#include <sstream>
#include <string>
#define HASH_SIZE 1301081
using namespace std;

struct Node {
    int n;
    Node *next;
};

string com;
stringstream sin;
Node *hashtable[HASH_SIZE];

int searchlist(int num){
    int index = num % HASH_SIZE;
    Node *c = hashtable[index];
    while(c -> next != NULL){
        if(c -> next -> n == num){
            if(c -> next -> next == NULL){
                c -> next = NULL;
                //cout << "deleting" << endl;
            } else {
                //cout << "rerouting" << endl;
                c -> next = c -> next -> next;
            }
            return index;
        }
        c = c->next;
    }
    return -1;
}

void clearI(Node *currentNode){
    if(currentNode -> next == NULL) return;
    Node *p = currentNode -> next;
    if(currentNode -> next -> next == NULL){

    }
}

void add(int num){
    int index = num % HASH_SIZE;
    Node *p = new Node;
    p -> n = num;
    p -> next = hashtable[index] -> next;
    hashtable[index] -> next = p;
}

int main(){
    for(int i = 0 ; i < HASH_SIZE; i++){
        hashtable[i] = new Node;
    }
    while(getline(cin, com)){
        for(int i = 0 ; i < HASH_SIZE; i++){
            hashtable[i] -> next = NULL;

        }
        int aL = 0, bL = 0, diff = 0, oB = 0; //diff will tell if disjoint
        sin.clear();
        sin.str(com);
        int num;
        while(sin >> num){
            aL++;
            add(num);
            //cout << "Inserted " << num << " at pos: " << index << endl;
        }
        getline(cin, com);
        sin.clear();
        sin.str(com);
        while(sin >> num){
            bL++;
            oB++;
            if(aL){ //if a is zero we're done
                int res = searchlist(num);
                if(res >= 0){ //deleted
                    aL--;
                    bL--;
                } else {//delete unsuccessful, do nothing
                    diff++;
                }
            }
        }
        //printf("aL: %d, bL: %d, oB: %d, diff: %d\n", aL, bL, oB, diff);
        if(aL*bL == 0){
            if(aL > 0){
                printf("B is a proper subset of A\n");
            } else if(bL > 0){
                printf("A is a proper subset of B\n");
            } else {
                printf("A equals B\n");
            }
        } else if(diff == oB){
            printf("A and B are disjoint\n");
        } else {
            printf("I'm confused!\n");
        }

    }
}
