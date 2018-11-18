#include <iostream>
using namespace std;
int main(){
    int a;
    while(cin >> a){
        if(a == 0){
            break;
        }
        for(int i = 1; i < a; i++){
            if(i % 7 != 0) cout << i << " ";
        }
        cout << endl;
    }
}
