#include <iostream>
using namespace std;

int N;
int A[3000][3000], B[3000][3000], C[3000][3000], AB[3000][3000];

void ArrMult(int A[][3005], int B[][3005], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            AB[i][j] = 0;
            for(int k = 0; k < N; k++){
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }

}




int main(){
    while(cin >> N){
        for(int i = 0; i < N;i ++){
            for(int j = 0 ; j < N; j++){
                cin >> A[i][j];
            }
        }
        for(int i = 0; i < N;i ++){
            for(int j = 0 ; j < N; j++){
                cin >> B[i][j];
            }
        }
        for(int i = 0; i < N;i ++){
            for(int j = 0 ; j < N; j++){
                cin >> C[i][j];
            }
        }

        ArrMult(A, B, N);
        bool flag = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(AB[i][j]!=C[i][j]){
                    flag = false;
                    break;
                }
            }
        }

        if(flag){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }



    }


}
