#include <iostream>
#include <string.h>
using namespace std;

string A, B;
int table[1001][1001];

int main(){

    while(getline(cin, A)){
        getline(cin , B);
        int lA = A.length(), lB = B.length();
        for(int i = 0; i <= lA; i++){
            for(int j = 0; j <= lB; j++){
                table[i][j] = 0;
            }
        }

        for(int i = 1; i <= A.length(); i++){
            for(int j = 1; j <= B.length(); j++){
                if(A[i-1] == B[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                } else {
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        cout << table[lA][lB] << endl;
        /*
        for(int i = 1; i <= A.length(); i++){
            for(int j = 1; j <= B.length(); j++){
                cout << table[i][j] << " ";

            }
            cout << endl;

        }
        */

    }

}
