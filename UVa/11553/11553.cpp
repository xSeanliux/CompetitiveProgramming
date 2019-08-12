#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int T, N, ans[10], ANS, cr;



int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        int arr[N][N], perm[N];
        for(int i = 0; i < N; i++) {
            perm[i] = i;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
            }
        }
        ANS = 2147483647;
        do{
            cr = 0;
            for(int i = 0; i < N; i++){
                cr += arr[i][perm[i]];
            }
            ANS = min(cr, ANS);
        } while(next_permutation(perm, perm + N));
        cout << ANS << endl;
    }
}
