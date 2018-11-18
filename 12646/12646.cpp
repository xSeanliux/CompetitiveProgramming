#include <iostream>
using namespace std;

int zeroes, ones;
int zI, oI;
int a[3];


int main(){
    while(cin >> a[0] >> a[1] >> a[2]){
        zeroes = 0, ones = 0;
        for(int i = 0; i < 3; i++){
            if(!a[i]){
                zeroes++;
                zI = i;
            } else {
                ones++;
                oI = i;
            }
        }
        if(zeroes == 1){
            cout << (char)(zI + 'A') << endl;
        } else if(ones == 1){
            cout << (char)(oI + 'A') << endl;
        } else {
            cout << "*" << endl;
        }
    }

}
