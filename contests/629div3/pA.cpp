#include <iostream>
using namespace std;

const int maxN = 2e5 + 10;

int N, q, arr[maxN], t[maxN], _t[maxN], cpos;

inline void solve(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    cpos = -1;
    for(int i = 0; i < N; i++){
        if(arr[i] == arr[(i + 1) % N]) cpos = i;
    }
    int cans = 1000, _ans = 1;
    for(int i = 1; i < N; i++){
        if(arr[i] != arr[0]) break;
        else if(i == N - 1){
            cout << 1 << endl;
            for(int i = 0; i < N; i++) cout << 1 << " ";
            cout << endl;
            return;
        }
    }
    if(N % 2 == 0){
        cout << 2 << endl;
        for(int i = 0; i < N; i++) cout << 1 + (i % 2) << " ";
        cout << endl;
        return;
    } else {
        if(cpos == -1){
            cout << 3 << endl;
            for(int i = 0; i < N - 1; i++) cout << 1 + (i % 2) << " ";
            cout << 3 << endl;
        } else {
            cout << 2 << endl;
            t[cpos] = t[(cpos + 1) % N] = 1;
            int cnt = 1;
            for(int i = (cpos + 2) % N; i != cpos; i = (i + 1) % N){
                t[i] = 1 + cnt;
                cnt ^= 1;
            }
            for(int i = 0; i < N; i++) cout << t[i] << " ";
            cout << endl;
        }
    }
}

int main(){
    cin >> q;
    while(q--){
        solve();
    }
}
