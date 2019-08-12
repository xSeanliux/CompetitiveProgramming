#include <iostream>
using namespace std;

int T, n, P, Q, arr[30], c = 0;

int main(){
    cin >> T;
    while(T--){
        cin >> n >> P >> Q;
        //printf("n = %d, P = %d, Q = %d\n", n, P, Q);
        int currentWeight = 0, a = -1;
        for(int i = 0; i < n; i++){
            //cout << "i = " << i << endl;
            cin >> arr[i];
            currentWeight += arr[i];
            if(currentWeight <= Q && i < P){
                a = i;
            }
        }
        printf("Case %d: %d\n", ++c, ++a);
    }
}
