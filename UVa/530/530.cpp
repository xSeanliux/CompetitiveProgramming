#include <iostream>
using namespace std;

long long int bin[200][200];

int n, k;
void calcbin(){
    for(int i = 2; i < 200; i++){
        for(int j = 0; j <= i; j++){
            if(!j || j == i) bin[i][j] = 1;
            else {
                bin[i][j] = bin[i-1][j-1] + bin[i-1][j];
                //cout << "bin[" << i << "][" << j << "] = " << bin[i][j] << endl;
            }

        }
    }
}

int main(){
        bin[0][0] = 1;
        bin[1][0] = 1;
        bin[1][1] = 1;
        calcbin();
    while(cin >> n >> k){
        if(!n && !k) return 0;
        if(!k || k == n) cout << 1 << endl;
        else {
            cout << bin[n][k] << endl;
        }
    }
}
