#include <iostream>
#include <math.h>
using namespace std;
int arr[100];
int N;
int sum1, sum2;
int n1, n2, n3, n4;
int main(){
    while(cin >> N){
        for(int i = 0; i < N; i++){

            cin >> n1 >> n2 >> n3 >> n4;
            sum1 = sum2 = 0;
            arr[0] = (int)floor(n1/1000)*2;
            arr[1] = (int)floor(n1/10)%10*2;
            arr[2] = (int)floor(n2/1000)*2;
            arr[3] = (int)floor(n2/10)%10*2;
            arr[4] = (int)floor(n3/1000)*2;
            arr[5] = (int)floor(n3/10)%10*2;
            arr[6] = (int)floor(n4/1000)*2;
            arr[7] = (int)floor(n4/10)%10*2;
            //cout << endl << "sum1 ";
            for(int i = 0; i < 8; i++){
                sum1 += arr[i]%10 + floor(arr[i]/10);
                //cout << " + " << arr[i]%10 + floor(arr[i]/10);
            }
            //cout << endl;
            sum2 = n1%10 + (int)floor(n1/100)%10 + n2%10 + (int)floor(n2/100)%10 + n3%10 + (int)floor(n3/100)%10 + n4%10 + (int)floor(n4/100)%10;
            //cout << "sum2: " << sum2 << endl;
            if(((int)sum1 + (int)sum2) % 10 != 0){
                cout << "Invalid" << endl;
            } else {
                cout << "Valid" << endl;
            }

        }
    }

}
