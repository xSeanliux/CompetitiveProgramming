#include <iostream>
#include <math.h>
using namespace std;
int sequence[105]; //max 100;
void run(int ori, int n, int iteration){ //gets the next number.
    if(n == 1){
        cout << ori << " is a happy number" << endl;
        return;
    }
    else{
        int sum = 0;
        int _tmp = n;
        while(_tmp != 0){
            sum += pow(_tmp%10, 2);
            _tmp /= 10;

        }
        sequence[iteration] = sum;
        for(int i = 0 ; i < iteration; i++){
            if(sum == sequence[i]){
                cout << ori << " is an unhappy number" << endl;;
                return;
            }
        }
        run(ori, sum, iteration+1);
    }
}
int main(){
    int N;
    while(cin >> N){
        run(N, N, 0);
    }

}
