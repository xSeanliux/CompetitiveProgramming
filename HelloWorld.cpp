#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <string.h>
#include <map>
#include <set>
using namespace std;

long long int a, b;
long long int sparse[23][1000000];



long long int getB(long long int N){
    int cycleLen = 1;
    while(N > 1){
        if(N % 2){
            N = 3*N + 1;
        } else {
            N /= 2;
        }
        cycleLen++;
    }
    return cycleLen;

}


long long int getCycle(long long int N){
    if(sparse[0][N]) return sparse[0][N];
    else if(N > 1000000){
        return getB(N);
    } else {
        if(N == 1){
            return 1;
        }
        if(N % 2){
            return getCycle(3*N + 1) + 1;
        } else {
            return getCycle(N/2) + 1;
        }
    }
}

long long int pow2[25];




int main(){
    pow2[0] = 1;
    for(int i = 1; i < 25; i++){
        pow2[i] = 2 * pow2[i-1];
    }
    for(int i = 1; i <= 1000000; i++){
        sparse[0][i] = 0;
    }
    for(int i = 1; i <= 1000000; i++){
        //cout << "i = " << i << endl;
        sparse[0][i] = getCycle(i);
        //cout << "i: " << i << ", cycle = " << sparse[0][i] << endl;
        //if(i <= 210 && i > 200) cout << "i: " << i << ", cycle = " << sparse[0][i] << endl;
    }
    //cout << sparse[0][999999] << endl;
    for(int i = 1; i <= 23; i++){
        for(int j = 1; j <= 1000000; j++){
            if(j <= 1000000 - pow2[i] + 1){
                sparse[i][j] = max(sparse[i-1][j], sparse[i-1][j + pow2[i-1]]);
                /*
                if(j == 1000000 - pow2[i] + 1){
                    cout << "sparse[" << i << "][" << j << "] = " << sparse[i][j] << endl;
                }
                */
            }
        }
    }
    while(cin >> a >> b){
        int oriA = a, oriB = b;
        if(b < a) swap(a, b);
        int layer = floor(log2(b - a + 1));
        //cout << "Layer: " << layer << endl;
        //cout << "sparse[" << layer << "][" << a << "] = " << sparse[layer][a] << endl;
        //cout << "sparse[" << layer << "][" << b - pow2[layer] << "] = " << sparse[layer][b - pow2[layer] + 1] << endl;
        cout << oriA << " " << oriB  << " " << max(sparse[layer][a], sparse[layer][b - pow2[layer] + 1]) << endl;
    }
}
