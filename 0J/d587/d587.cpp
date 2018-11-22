#include <iostream>
using namespace std;



int main(){
    int len, one, two, three;
    while(cin >> len){
        int arr[len];

        for(int i = 0 ; i < len; i++){

            cin >> arr[i];
            if(arr[i] == 1) one++;
            if(arr[i] == 2) two++;
            if(arr[i] == 3) three++;
        }


        if(len % 3 == 0 & one == two & two == three){
            for(int i = 1 ; i <= 3; i++){
                for(int j = 1; j <= len/3; j++){
                    cout << i << " " ;
                }
            }

        } else {
            for(int i = 0; i < len; i++){
                for(int j = i+1; j < len; j++){
                    if(arr[i] >= arr[j]){
                        int tmp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = tmp;
                    }
                }



            }
             for(int i = 0 ; i < len; i++){
                    cout << arr[i] << " ";
                }


        }
    }


}

