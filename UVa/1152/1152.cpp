#pragma gcc optimize ("O3")
#include <iostream>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

unordered_map<int, int> mp;
vector<int> A, B, C, D;
int T, N, a, b, c, d;
bool hasPrint = false;n

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N;
        mp.clear();
        A.reserve(N); B.reserve(N); C.reserve(N); D.reserve(N);
        A.clear(); B.clear(); C.clear(); D.clear();
        for(int i = 0; i < N; i++){
            cin >> A[i] >> B[i] >> C[i] >> D[i];
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                mp[A[i] + B[j]]++;
            }
        }
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                ans += mp[-C[i] - D[j]];
            }
        }
        if(!hasPrint) hasPrint = true;
        else cout << endl;
        cout << ans << endl;
    }
}
