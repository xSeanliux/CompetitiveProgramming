#include <iostream>
using namespace std;

int ans, N, t;

int main(){
    while(cin >> ans){
        t = 0;
        for(int i = 0 ; i < 5; i++){
            cin >> N;
            t += (N == ans);
        }
        cout << t << endl;
    }
}
