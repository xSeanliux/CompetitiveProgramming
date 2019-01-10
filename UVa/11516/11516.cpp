#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define pb push_back
using namespace std;

int T, N, K, _t; //T tests, can buy N, K houses.
vector<int> houses;

bool canPlace(int diam){
    bool arr[houses.size()];
    memset(arr, false, houses.size());
    int currentUse = 0;
    for(int i = 0; i < houses.size(); i++){
        if(!arr[i]){
            arr[i] = true;
            //cout << "Putting one at " << houses[i] + diam/2.0 << endl;
            int current = houses[i];
            while(i < houses.size() && houses[i] - current <= diam){
                arr[i] = true;
                //cout << houses[i] << " has been covered" << endl;
                i++;
            }
            currentUse++;
            i--;
        }
        if(currentUse > N) return false;
    }
    return true;
}
//------- farthest: current + diam (incl)
int main(){
    cin >> T;
    while(T--){
        houses.clear();
        scanf("%d%d", &N, &K);
        for(int i = 0 ; i < K; i++){
            scanf("%d", &_t);
            houses.pb(_t);
        }
        if(N >= K){
            printf("0.0\n");
            continue;
        }
        //cout << "HOUSES: " << houses.size() << endl;
        sort(houses.begin(), houses.end());
        int uD = houses[houses.size() - 1], lD = 1, mD = (lD + uD)/2;
        while(uD - lD > 0.5){
            //cout << "trying mD = " << mD << endl;
            if(canPlace(mD) && !canPlace(mD-1)){
                printf("%.1f\n", mD/2.0);
                break;
            }
            if(canPlace(mD)){
                //cout << "too large" << endl;
                uD = mD;
            } else {
                //cout << "too small" << endl;
                lD = mD;
            }
            mD = (lD + uD)/2;
        }

    }
}
