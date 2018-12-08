#include <iostream>
using namespace std;


int N, M;

int main(){
    while(cin >> N >> M){
        int ans = 0, n;
        bool hasZero;
        for(int i = 0 ; i < N; i++){
            hasZero = false;
            for(int j = 0 ; j < M; j++){
                cin >> n;
                if(!n)
                    hasZero = true;
            }
            ans += !hasZero;
        }
        cout << ans << endl;
    }
}
