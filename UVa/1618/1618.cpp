#include <iostream>
using namespace std;

int T, N, arr[5002], ans[5002][2]; //0 for bigger, 1 for smaller
bool canDo;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    scanf("%d", &T);
    while(T--){
        cin >> N;
        canDo = false;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            ans[i][0] = 1;
            ans[i][1] = 1;
        }
        for(int i = 1; i < N && !canDo; i++){
            for(int j = 0; j < i; j++){
                if(arr[j] > arr[i]){
                    ans[i][1] = max(ans[i][1], ans[j][1] + 1);
                } else if(arr[j] < arr[i]){
                    ans[i][0] = max(ans[i][0], ans[j][0] + 1);
                }
                if(ans[i][0] >= 4 || ans[i][1] >= 4){
                    canDo = true;
                    break;
                }
            }
            printf("%d: bigger chain: %d, smaller chain: %d\n", i, ans[i][0], ans[i][1]);
        }
        if(canDo){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
