#pragma GCC optimize ("O3")
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, _t;
vector<int> a, b;
priority_queue<int> que;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> _t;
        a.push_back(_t);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> _t;
        b.push_back(_t);
    }
    a.push_back(-1);
    b.push_back(-1);
    int i = 0, j = 0;
    if(a[i] >= b[i]){
        cout << a[0];
        i = 1;
    } else {
        cout << b[0];
        j = 1;
    }
    while(i + j < M+N){
        if(a[i] >= b[j]){
            cout << " " << a[i];
            i++;
        } else {
            cout << " " << b[j];
            j++;
        }
    }
}
