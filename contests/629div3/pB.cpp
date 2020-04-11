#include <iostream>
using namespace std;

int q, N, K;
char arr[200010];
void solve(){
    cin >> N >> K;
    for(int pos = 1; pos < N; pos++){
        if(K <= pos){
            //cout << "Pos = " << pos << endl;
            //cout << "k = " << K << endl;
            fill(arr, arr + N, 'a');
            arr[pos] = 'b';
            arr[K - 1] = 'b';
            for(int i = N - 1; i >= 0; i--) cout << (char)arr[i];
            cout << endl;
            return;
        }
        K -= (pos);
    }
}

int main(){
    cin >> q;
    while(q--){
        solve();
    }
}
