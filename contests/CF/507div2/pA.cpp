#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
using namespace std;

int N, bc, wc;
vector<int> vec;

int main(){
    cin >> N >> wc >> bc;
    vec.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }
    bool canDo = true;
    int minCost = 0;
    for(int i = 0; i < N/2; i++){
        if((vec[i] == 0 && vec[N - i - 1] == 1) || (vec[i] == 1 && vec[N - i - 1] == 0)){
            canDo = false; break;
        } else if(vec[i] == 2 && vec[N - i - 1] == 2){
            minCost += 2 * min(bc, wc);
        } else if((vec[i] == 0 && vec[N - i - 1] == 2) || (vec[i] == 2 && vec[N - i - 1] == 0)){
            minCost += wc;
        } else if((vec[i] == 2 && vec[N - i - 1] == 1) || (vec[i] == 1 && vec[N - i - 1] == 2)){
            minCost += bc;
        }
    }
    if(N % 2 && vec[N/2] == 2) minCost += min(bc, wc);
    cout << (canDo ? minCost : -1) << endl;
}
