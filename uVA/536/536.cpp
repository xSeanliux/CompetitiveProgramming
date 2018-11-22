#include <iostream>
#include <string.h>
using namespace std;


string pre, in;
int c = 0;

//post: left, right, root;

void run(string pre, string in){
    if(pre.length() == 0 || in.length() == 0) return;
    char root = pre[0];
    int i, j, l = pre.length();
    if(l <= 1){
        cout << root;
        return;
    }
    for(i = 0; i < l; i++){
        if(in[i] == root) break;
    }
    string inl = in.substr(0, i);
    string inr = in.substr(i + 1);
    //cout << inl << " " << inr << endl;
    string prel = pre.substr(1, inl.length());
    string prer = pre.substr(inl.length() + 1);
    //cout << prel << " " << prer << endl;
    if(l > 1){
        run(prel, inl);
        run(prer, inr);
    }
    cout << root;
}

int main(){
    while(cin >> pre >> in){
        if(!c) c++;
        else cout << endl;
        run(pre, in);
    }
}
