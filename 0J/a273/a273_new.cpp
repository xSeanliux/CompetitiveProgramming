#include <iostream>
using namespace std;

int n, k;

int main(){
    while(cin >> n >> k){
        if((n == k) || k && !(n % k)){
            cout << "Ok!" << endl;
        } else {
            cout << "Impossib1e!" << endl;
        }
    }
}
