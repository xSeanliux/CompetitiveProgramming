#include <iostream>
#define INF 2147483647
using namespace std;

int N, B, H, W;

int main(){
    while(cin >> N >> B >> H >> W){ //N people, B budget, H hotels, W weeks to choose
        //cout << "N = " << N << endl;
        int minCost = INF,  p;
        for(int i = 0 ; i < H; i++){
            cin >> p;
            bool canDo = false;
            int k;
            for(int j = 0 ; j < W; j++){
                cin >> k;
                if(k >= N){
                    //cout << "N = " << N << ", k = " << k << endl;
                    canDo = true;
                }
            }
            if(canDo){
                //cout << "can do. " << endl;
                minCost = min(minCost, N * p);
            }
            //cout << "no" << endl;
        }
        if(minCost > B){
            cout << "stay home" << endl;
        } else {
            cout << minCost << endl;
        }
    }
}
