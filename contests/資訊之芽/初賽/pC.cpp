#include <iostream>
using namespace std;

int T, N, M;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        int ans = 0;
        if(M % 2){
            if(((M + 1)/2 + N) % 2 == 0){
                ans += 1;
                ans += (M+1)/2;
                ans += ((M + 1)/2 + N)/2;
            } else {
                ans += 3;
                ans += (M+3)/2;
                ans += ((M + 3)/2 + N)/2;
            }
        } else {
            if(((M)/2 + N) % 2 == 0){
                ans += M/2;
                ans += ((M/2) + N)/2;
            } else {
                ans += (M+2)/2 + 2;
                ans += (((M+ 2)/2) + N)/2;
            }
        }
        cout << ans << endl;
    }
}
