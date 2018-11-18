#include <iostream>
using namespace std;
int main(){
    int num;
    int ans;
    while(cin >> num){
        ans = 0;
        if(num == 0){
            break;
        }
        for(int i = num; i> 0; i--){
            ans += i*i;
        }
        cout << ans << endl;



    }
}


