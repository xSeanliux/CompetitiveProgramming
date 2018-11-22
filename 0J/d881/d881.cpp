#include <iostream>
using namespace std;
long long int nums[55]; //50 numbers;
long long int sum = 0;
//An = An-1 + diff*(n-1);
//An+1 = An + diffn;

//DIFFn = 1 + (n-1)diff
//DIFF1 = 1 +
int main(){

    int diff;
    while(cin >> diff){
        sum = 0;
        nums[1] = 1;
        nums[2] = 2;
        //int act_diff = 1 + ()
        for(int i = 3; i <= 50; i++){
            nums[i] = nums[i-1] + (nums[i-1] - nums[i-2]) + diff;
            sum += nums[i];
            //cout << nums[i] << " + ";
        }
        cout << sum + 3 << endl;
    }
}
