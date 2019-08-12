#include <iostream>
using namespace std;

unsigned long long int n, vals[100005], dp[5][100005], MOD = 1e9 + 7;
bool flag = false;

int main(){
    while(cin >> n){
        unsigned long long int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> vals[i];
        }
        if(!flag) flag = true;
        else cout << endl;
        if(n < 4){
            cout << 0;
            continue;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    for(int l = k + 1; l < n; l++){
                        ans = (ans + (((((vals[i]*vals[j])%MOD)*vals[k])%MOD)*vals[l]))%MOD;
                    }
                }
            }
        }
        cout << ans;
    }
}
