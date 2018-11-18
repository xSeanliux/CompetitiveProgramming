#include <iostream>
using namespace std;

int l1, l2;
int arr1[100], arr2[100];
int dp[100][100];

int lcs(){
    for(int i = 0 ; i <= max(l1, l2); i++){
        dp[0][i] = dp[i][0] = 0;
    }
    for(int i = 1 ; i <= l1; i++ ){
        for(int j = 1; j  <= l2; j++){
            if(arr1[i-1] == arr2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[l1][l2];
}



int main(){
    cin >> l1 >> l2;
    for(int i = 0 ; i < l1 ; i++){
        cin >> arr1[i];
    }
    for(int i = 0 ; i < l2 ; i++){
        cin >> arr2[i];
    }
    cout << lcs() << endl;
}
