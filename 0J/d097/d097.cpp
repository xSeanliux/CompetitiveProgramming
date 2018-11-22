#include <iostream>
#include <math.h>
using namespace std;
bool used[3005]; //max 3000
int nums[3005];
int main(){
    int len;
    bool flag;
    while(cin >> len){
        flag = true;
        for(int i = 0 ; i < len; i++){
            cin >> nums[i];
            used[i] = false;
        }
        for(int i = 1; i < len; i++){
            used[abs(nums[i] - nums[i-1])] = true;
            //cout << "Used[" << abs(nums[i] - nums[i-1]) << "] is now true" << endl;
        }
        for(int i = 1; i < len-1; i++){
            if(!used[i]){
                flag = false;
            }
        }
        if(flag){
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }
    }


}
