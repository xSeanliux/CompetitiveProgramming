#include <iostream>
using namespace std;

long long int n;

int main(){
    while(cin >> n){
        long long int k = n + 1;
        cout << (n * n * k * k)/ 4 << endl;
    }


}
