#include <iostream>
using namespace std;


int k, n;
bool isHard = false;
int main(){
    cin >> k;
    for(int i = 0 ; i < k ; i++){
        cin >> n;
        if(n == 1) isHard = true;
    }
    cout << ((isHard) ? "HARD" : "EASY") << endl;
}
