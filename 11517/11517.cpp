#include <iostream>
using namespace std;
int c, price, bills, head;
int dp[10000 + 5], bills[10000];



int main(){
    cin >> c;
    for(int ia = 0 ; ia < c; ia++){
        cin >> price;
        cin >> bills;
        head = 0;
        memset(dp, 0, sizeof(dp));
        int t;
        for(i = 0; i < bills; i++){
            cin >> t;
            bills[head] = t;
            head++;
        }
        sort(bills, bills + head);
        for(int i = head - 1; i >= 0; i--){
            int cB = bills[i];
            for(int j = 0; j < 10000; j+=cB){

            }
        }
    }

}
