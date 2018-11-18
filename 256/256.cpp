#include <iostream>
using namespace std;

int k;

int main(){
    while(cin >> k){
        if(k == 2){
            for(int a = 0 ; a < 10; a++){
                for(int b = 0; b < 10; b++){
                    if((a + b)*(a + b) == 10*a + b){
                        cout << a << b << endl;
                    }
                }
            }
        } else if(k == 4){
            for(int a = 0 ; a < 100; a++){
                for(int b = 0; b < 100; b++){
                    if((a + b)*(a + b) == 100*a + b){
                        printf("%02d%02d\n", a, b);
                    }
                }
            }
        } else if(k == 6){
            for(int a = 0 ; a < 1000; a++){
                for(int b = 0; b < 1000; b++){
                    if((a + b)*(a + b) == 1000*a + b){
                        printf("%03d%03d\n", a, b);
                    }
                }
            }
        } else if(k == 8){
            for(int a = 0 ; a < 10000; a++){
                for(int b = 0; b < 10000; b++){
                    if((a + b)*(a + b) == 10000*a + b){
                        printf("%04d%04d\n", a, b);
                    }
                }
            }
        }
    }
}
