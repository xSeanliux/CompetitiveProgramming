#include <iostream>
using namespace std;
int main(){
    int N, M;
    int f_start, f_end, _tmp;
    int foods[100006];
    foods[0] = 0;

    while(cin >> N >> M){
        cin >> foods[1];

        for(int i = 2 ; i <= N; i++){

            cin >> _tmp; //input the foods
            foods[i] = foods[i-1] + _tmp;


        }
        for(int i = 0 ; i < M ; i++){// input the foods

            cin >> f_start >> f_end;
            cout << (foods[f_end] - foods[f_start-1]) << endl;
        }
    }
}
