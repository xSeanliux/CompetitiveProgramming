#include <iostream>
using namespace std;

int main(){
    int N;
    while(cin >> N){
        int nums[N], maximum = 0;
        for(int i = 0 ; i < N; i++){
            cin >> nums[i];
            if(nums[i] > maximum) maximum = nums[i];
        }
        cout << maximum << endl;

    }

}
