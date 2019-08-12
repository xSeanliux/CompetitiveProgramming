#include <iostream>
#include <string.h>
using namespace std;

int T, n, ans;
string currentPre, s;

struct Node{
    int amnt, depth;
    Node* zeroChild;
    Node* oneChild;
    Node(int amnt, int dept): amnt(amnt), depth(dept), zeroChild(nullptr), oneChild(nullptr){}
    Node(){}
};

void go(string s, int index, Node* currentNode){
    if(index == s.length()) return;
    currentNode->amnt++;
    if(currentNode->depth * currentNode->amnt > ans) ans = currentNode->depth * currentNode->amnt;
    char c = s[index + 1];
    if(c == '0' && !currentNode->zeroChild) currentNode->zeroChild = new Node(0, index + 1);
    if(c == '1' && !currentNode->oneChild) currentNode->oneChild = new Node(0, index + 1);
    if(c == '0') go(s, index + 1, currentNode->zeroChild);
    if(c == '1') go(s, index + 1, currentNode->oneChild);
}

int main(){
    cin >> T;
    while(T--){
        cin >> n;
        Node* root = new Node(0, 0);
        ans = 0;
        for(int i = 0; i < n; i++){
            cin >> s;
            s = '-' + s; //- stands for root character
            go(s, 0, root);
        }
        cout << ans << endl;
    }
}
