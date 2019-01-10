#include <iostream>
using namespace std;

long long int sols[15];


int n, K = 0;


void getSols(){
    sols[0] = 1;
    sols[1] = 1;
    //sols[2] = 2;
    for(int i = 2; i <= 10; i++){ //2 * i dots
        sols[i] = 0;
        for(int j = 0; j < i; j++){
            sols[i] += sols[j]*sols[i-j-1];
        }
        //cout << i << ": " << sols[i] << endl;
    }
}

int main(){
    getSols();
    while(cin >> n){
        if(!K)
            K = 1;
        else
            cout << endl;
        cout << sols[n] << endl;;
    }
}
