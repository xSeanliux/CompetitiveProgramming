#include <iostream>
using namespace std;

int n, k;
int main(){
    cin >> n >> k;
    int minX = 2147483647;
    for(int i = 1; i < k; i++){
        if(!(n % i)){ //x equiv i (mod k)
            //cout << "Found i = " << i << endl;
            minX = min(minX, n*k/i + i);
        }
    }
    cout << minX << endl;
}
