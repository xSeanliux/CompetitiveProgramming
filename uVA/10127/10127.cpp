#include <iostream>
#define INF 169696969
using namespace std;
int N;


int main(){
    while(cin >> N){
        int mod[N+1]; //modulus value of how many zeroes
        mod[1] = 1;
        for(int i = 2; i <= N+1; i++){
            mod[i] = (10*mod[i-1] + 1) % N;
            //cout << "mod[" << i << "] = " <<mod[i] << endl;
        }
        int minDist = INF;
        for(int i = 1; i <= N + 1; i++){
            for(int j = i + 1; j <= N + 1; j++){
                if(mod[i] == mod[j]){
                    minDist = min(minDist, j - i);
                    break;
                }
            }
        }
        cout << minDist << endl;
    }
}

