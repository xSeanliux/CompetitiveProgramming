#include <iostream>
using namespace std;
long long fibList[1000];

long long f(int n){
    if(fibList[n-1] == 0 | fibList[n-2] == 0 & n >= 3){
        f(n-1);
    }

    if(n == 0){
        return 1;
    } else if(n == 1){
        return 2;
    } else {
        fibList[n] =fibList[n-1] + fibList[n-2];
        return fibList[n];
    }

}


int main(){
    fibList[0] = 1;
    fibList[1] = 2;
    int cases, n;


    while(cin >> cases){

        for(int i = 1; i <= cases; i++){
            cin >> n;
            cout << "Scenario #" << i << ":"<< endl << f(n) << endl << endl;
        }
    }





}

