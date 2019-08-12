#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int N, dists[1430];

int main(){
    while(cin >> N){
        if(!N) return 0;
        bool canDo = true;
        for(int i = 0; i < N; i++) cin >> dists[i];
        sort(dists, dists + N);
        for(int i = 1; i < N; i++){
            cout << "comparing " << dists[i] << " and " << dists[i - 1] << endl;
            if(dists[i] - dists[i - 1] > 200){
                //cout << "Nope" << endl;
                canDo = false;
                break;
            }
            if(i == N - 1){
                cout << "canDo: " << canDo << endl;
                canDo = min(canDo, ((1422 - dists[i]) <= 100));
                cout << "after: " << canDo << endl;
            }
        }
        if(canDo){
            cout << "POSSIBLE" << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}
