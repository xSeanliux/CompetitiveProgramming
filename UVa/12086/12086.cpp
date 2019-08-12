#pragma gcc optimize ("O3")
#include <iostream>
#include <string.h>
using namespace std;

int bit[200069], arr[200069], N, a, b, c = 0;
string s;
bool flag = false;

int lowBit(int x){
    return x & -x;
}

int sum(int p){
    int res = 0;
    for(;p;p -= lowBit(p)) res += bit[p];
    return res;
}

void add(int p, int x){
    for(;p <= N; p += lowBit(p)) bit[p] += x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> N){
        if(!N) return 0;
        arr[0] = 0;
        for(int i = 0; i <= N; i++) bit[i] = 0;
        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
            add(i, arr[i]);
        }
        if(flag) cout << endl;
        else flag = true;
        cout << "Case " << ++c << ":" << endl;
        while(cin >> s){
            if(s == "END") break;
            if(s == "M"){
                cin >> a >> b;
                cout << sum(b) - sum(a - 1) << endl;
            } else {
                cin >> a >> b;
                add(a, b - arr[a]);
                arr[a] = b;
            }
        }
   }
}
