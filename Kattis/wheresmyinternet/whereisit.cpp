#include <iostream>
using namespace std;

int N, Q, disjoint[200005];

void sortOut(int n){
    if(disjoint[n] == n){
        return;
    } else {
        sortOut(disjoint[n]);
        disjoint[n] = disjoint[disjoint[n]];
    }
}


int main(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++)
        disjoint[i] = i;
    for(int i = 0; i < Q; i++){
        int a, b;
        cin >> a >> b;
        sortOut(a);
        sortOut(b);
        disjoint[disjoint[a]] = disjoint[b];
    }
    for(int i = 1;  i <= N; i++){
        sortOut(i);
    }
    int ances = disjoint[1];
    bool flag = false;
    for(int i = 2; i <= N; i++){
        if(disjoint[i] != ances){
            flag = true;
            cout << i << endl;
        }
    }
    if(!flag) cout << "Connected" << endl;
}
