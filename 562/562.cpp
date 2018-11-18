#include <iostream>
#include <math.h>
using namespace std;
int cases, coins;
int coinarr[100 + 5];
bool canGo[500 * 100 + 100];
int main(){
    cin >> cases;
    for(int ik = 0; ik < cases; ik++){
        cin >> coins;
        int sum = 0;
        for(int i = 0; i < coins; i++){
            cin >> coinarr[i];
            sum += coinarr[i];
        }
        for(int i = 0; i < sum ; i++){
            canGo[i] = false;
        }
        canGo[0] = true;
        for(int i = 0; i < coins; i++){
            //cout << "Coin: " << coinarr[i] << endl;
            for(int j = sum - coinarr[i]; j >= 0; j--){
                if(canGo[j]){

                    canGo[j + coinarr[i]] = true;
                    //cout << j + coinarr[i] << " can be reached" << endl;
                }

            }
        }
        int mid = (sum/2);
        //cout << "Mid: " << mid << endl;
        for(int i = mid; i >= 0; i--){
            if(canGo[i]){
                cout << abs(sum - 2*i) << endl;
                break;
            }
        }

    }
}
