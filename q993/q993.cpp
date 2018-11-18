#include <iostream>
using namespace std;

int findAns(int num){
    int ans = 0;
    if(num == 1) return 1;
    while(num != 1){
        for(int i = 2; i < 10; i++){
            if(num % i == 0){
                cout << "found " << i << endl;
                ans += i;

                num /= i;
                cout << "num is now" << num << endl;
                ans *= 10;
                cout << "ans is now" << ans << endl;
                break;
            } else if(i == 9 && num != 1){
                return -1;
            }
        }

    }
    return ans/10;
}


int main(){
    int num;
    while(cin >> num){
        cout << findAns(num) << endl;
    }




}
