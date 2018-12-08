#include <iostream>
using namespace std;

int a, b, carry;
int A[15], B[15];
int main(){
    carry = 0;
    int times = 0;
    while(cin >> a >> b){
        times = 0;
        carry = 0;
        for(int i = 0 ; i < 10; i++){
            A[i] = B[i] = 0;
        }
        if(a == 0 && b == 0){
            return 0;
        }
        int k = 0;
        while(a > 0){
            int d = a%10;
            A[k] = d;
            //cout << A[k] << endl;
            a -= d;
            a /= 10;
            k++;
        }
        k = 0;
        while(b > 0){
            int d = b%10;
            B[k] = d;
            //cout << B[k] << endl;
            b -= d;
            b /= 10;
            k++;
        }
        for(int i = 0; i < 10; i++){
            if(A[i] + B[i] + carry >= 10){
                carry = 1;
                times++;
            } else {
                carry = 0;
            }
        }
        if(times == 0){
            cout << "No";
        } else {
            cout << times;
        }
        cout << " carry operation";
        if(times > 1){
            cout << "s";
        }
        cout << "." << endl;

    }

}
