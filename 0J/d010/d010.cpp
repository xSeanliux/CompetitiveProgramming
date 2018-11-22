#include <iostream>
using namespace std;

int main(){
    int N, sum;
    while(cin >> N){
        int tmp = N;
        sum = 0;
        for(int i = 1; i < N; i++){
            if(N %i == 0) sum += i;
        }
        if(sum > tmp){
            cout << "盈數" << endl;
        } else if(sum == tmp){
            cout << "完全數" << endl;
        } else if(sum < tmp){
            cout << "虧數" << endl;
        }
    }
}
