#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string vOrder = "AUEOI", cOrder = "JSBKTCLDMVNWFXGPYHQZR";
int T, c = 0, N;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        int neededV = N/2, neededC = N/2;
        if(N % 2){
            neededV++;
        }
        string V = "", C = "";
        int toAdd, ind = 0;
        while(neededV){
            toAdd = min(21, neededV);
            for(int i = 0; i < toAdd; i++){
                V += vOrder[ind];
            }
            ind++;
            neededV -= toAdd;
        }
        ind = 0;
        while(neededC){
            toAdd = min(5, neededC);
            for(int i = 0; i < toAdd; i++){
                C += cOrder[ind];
            }
            ind++;
            neededC -= toAdd;
        }
        sort(V.begin(), V.end());
        sort(C.begin(), C.end());
        printf("Case %d: ", ++c);
        for(int i = 0; i < N/2; i++){
            cout << V[i] << C[i];
        }
        if(N % 2) cout << V[N/2];
        cout << endl;
    }
}
