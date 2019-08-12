#include <iostream>
#include <string.h>
using namespace std;


string pre, ino;

void printTree(int prel, int prer, int inol, int inor){
    //printf("Running pT(%d, %d, %d, %d)\n", prel, prer, inol, inor);
    if(prer <= prel || inor <= inol) return;
    if(prer - prel <= 1){
        cout << pre[prel];
        return;
    };
    char r = pre[prel];
    int midAt;
    for(midAt = inol; midAt < inor; midAt++) if(ino[midAt] == r) break;
    //there are midAt - inol in left subtree
    //printf("MIDAT: %d\n", midAt);
    printTree(prel + 1, prel + 1 + midAt - inol, inol, midAt);
    printTree(prel + 1 + midAt - inol, prer, midAt + 1, inor);
    cout << r;
}

int main(){
    while(cin >> pre >> ino){
        printTree(0, pre.length(), 0, ino.length());
        cout << endl;
    }
}
