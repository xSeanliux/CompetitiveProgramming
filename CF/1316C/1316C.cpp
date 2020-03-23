#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, M, P, fa, fb, x;

int main(){
    ericxiao;
    cin >> N >> M >> P;
    fa = fb = -1;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(x % P && fa == -1) fa = i;
    }
    for(int i = 0; i < M; i++){
        cin >> x;
        if(x % P && fb == -1) fb = i;
    }
    cout << fa + fb << '\n';
}
