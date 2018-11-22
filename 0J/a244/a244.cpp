#include <iostream>
using namespace std;
int main(){
    long long int nums, a, b ,c;
    while(cin >> nums){
        for(int i = 0; i < nums; i++){
            while(cin >> a >> b >> c){
                if(a == 1){
                    cout << b + c << endl;
                } else if (a == 2){
                    cout << b - c << endl;
                } else if(a == 3){
                    cout << b * c << endl;
                } else if (a == 4){
                    cout << b / c << endl;
                }
            }
        }
    }
}
