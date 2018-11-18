#include <iostream>
using namespace std;
int main(){

    int noofnums, num, mod0, mod1, mod2;
    while(cin >> noofnums){
        mod0 = 0, mod1 = 0; mod2 = 0;
        for(int i = 0; i < noofnums; i++){

            num = 0;
            cin >> num;
            cout << "Num: " << num;

            if(num % 3 == 0){
                cout << num << " % 3 == 0" << endl;
                ++mod0;
            } else if(num % 3 == 1){
                cout << num << " % 3 == 1" << endl;
                ++mod1;
            } else if(num % 3 == 2){
                cout << num << " % 3 == 2" << endl;
                ++mod2;
            }


        }
        cout << mod0 << " " << mod1 << " " << mod2 << " " << endl;
    }

}
