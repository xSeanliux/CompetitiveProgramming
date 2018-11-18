#include <iostream>
using namespace std;
int N;
int arr[100 + 5];
int main(){
    int T;
    while(cin >> T){
        for(int il = 0; il < T; il++){
            int N;
            cin >> N;
            int k;
            for(int i = 0; i < 105; i++){
                arr[i] = 0;
            }
            for(int i = 0; i < N; i++){
                cin >> k;
                arr[k]++;
            }
            int target =  (N+1)/2;
            int totalCows = 0;
            int ans;
            for(int i = 0 ; i < 101; i++){

                    totalCows += arr[i];

                    if(arr[i] && totalCows > target){
                        ans = i;
                        break;
                    }

            }
            cout << ans-1 << endl;
        }


    }
}
