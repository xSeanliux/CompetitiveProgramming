#include <iostream>
using namespace std;
int nums[35]; //max is 30 numbers;

int gcd(int a, int b){
    while(b){
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void run(int num, int len, int iteration){
    if(iteration == len){
        int sum = 0, currentGCD = 1;
        for(int i = 0 ; i < len ; i++){
            sum += nums[i];
        }


        if(sum == num){
            for(int i = 0 ; i < len ; i++){
                cout << nums[i] << " ";
            }
            cout << endl;
        }

        return;
    } else {
        for(int i = nums[iteration]; i < num; i++){
           nums[iteration] = i;
           run(num, len, iteration+1);
        }
    }



}



int main(){
    int cases, num, len;
    cout << gcd(10, 5) << endl;
    while(cin >> cases){
        for(int i = 0 ; i < cases; i++){
            for(int i = 0; i < len; i++){
                nums[i] = 0;
            }
            cin >> num >> len;
            run(num, len, 0);
        }
    }

}
