#include <iostream>
#include <vector>
using namespace std;

int n, m, k, seq[10];
bool hasn[10], hasm[10];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }
    for(int i = 0; i < 10; i++) hasm[i] = false;
    for(int i = 0; i < m; i++){
        cin >> k;
        hasm[k] = true;
    }
    for(int i = 0; i < n; i++){
        if(hasm[seq[i]]) cout << seq[i] << " ";
    }
}
