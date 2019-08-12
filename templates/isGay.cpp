#include <iostream>
using namespace std;

int N, M, a, b, dsu[(int)2e5 + 10];

void flat(int x){
    if(dsu[x] == x) return;
    flat(dsu[x]);
    dsu[x] = dsu[dsu[x]];
}

void Union(int a, int b){
    flat(a); flat(b);
    dsu[dsu[a]] = dsu[b];
}

int main(){
    while(cin >> N){
        if(!N) return 0;
        cin >> M;
        for(int i = 0; i <= 2 * N; i++) dsu[i] = i;
        bool isGood = true;
        for(int i = 0; i < M; i++){
            cin >> a >> b;
            flat(a); flat(b); flat(a + N); flat(b + N);
            if(dsu[a] == dsu[b] || dsu[a + N] == dsu[b + N]){
                isGood = false;
                break;
            } else {
                Union(a, b + N);
                Union(b, a + N);
            }
        }
        if(isGood){
            cout << "NORMAL." << endl;
        } else {
            cout << "RAINBOW." << endl;
        }
    }
}
