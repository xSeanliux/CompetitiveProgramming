#include <iostream>
using namespace std;



int n1, n2;
int A[300];
int B[300];
int table[300][300];

int main(){
    int round = 1;
    while(cin >> n1 >> n2){
        if(n1 == 0 && n2 == 0){
            return 0;
        }
        for(int i = 1; i <= n1; i++){
            cin >> A[i];
        }
        for(int i = 1; i <= n2; i++){
            cin >> B[i];
        }
        int maxNum = 0;
        for(int i = 0; i <= n1; i++){
            for(int j = 0; j <= n1; j++){
                table[i][j] = 0;
            }
        }

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(A[i] == B[j]){
                    table[i][j] = table[i-1][j-1] + 1;
                } else {
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
                if(table[i][j] >= maxNum){
                maxNum = table[i][j];
            }
            }

        }

        cout << "Twin Towers #" << round<<endl;
        cout << "Number of Tiles : " << maxNum << endl;
        round++;

    }

}
