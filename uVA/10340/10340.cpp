#include <iostream>
#include <string.h>
using namespace std;

string a, b;

int main(){
    while(cin >> a >> b){

        int lenA = a.size();
        int lenB = b.size();
        int i_A = 0;
        int i_B = 0;
        bool correct = true;
        while(i_A < lenA && correct){
            for(int i = i_B; i < lenB; i++){
                if(a[i_A] == b[i]){
                    //cout << a[i_A] << " " << i << endl;
                    i_A++;
                    i_B = i+1;
                    break;
                }else if(i == lenB-1){
                    correct = false;
                }
            }
        }
        cout << (i_A >= lenA ? "Yes" : "No") << endl;
    }
}



