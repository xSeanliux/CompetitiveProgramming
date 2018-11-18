#include <iostream>
#include <cmath>
using namespace std;

int bestRoad[100 + 5][100 + 5], s, e, c, N, R, k = 0;

int main(){
    while(cin >> N >> R){
        if(!N && !R) return 0;
        for(int i = 0 ; i < 105; i++){
            for(int j = 0 ; j < 105; j++){
                bestRoad[i][j] = 0;
            }
        }
        for(int i = 0 ; i < R; i++){
            cin >> s >> e >> c;
            bestRoad[s][e] = c;
            bestRoad[e][s] = c;
        }
        for(int i = 1; i <= N; i++){
            bestRoad[i][i] = 0;
        }
        for(int k = 1 ; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    bestRoad[i][j] = max(min(bestRoad[i][k], bestRoad[j][k]), bestRoad[i][j]);
                    //cout << "bestRoad[" << i << "][" << j << "] = " << bestRoad[i][j] << endl;
                }
            }
        }
        printf("Scenario #%d\n", ++k);
        cin >> s >> e >> c;
        cout << "Minimum Number of Trips = " << ceil((c + 0.0)/(bestRoad[s][e]-1))<< endl << endl;

    }

}
