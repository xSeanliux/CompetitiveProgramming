#include <iostream>
#include <fstream>
using namespace std;

int T, N, P[50 + 6];

int main(){
    cin >> T;
    ofstream myfile;
    myfile.open ("output2.txt");
    for(int k = 1 ; k <= T; k++){
        cin >> N;
        for(int i = 0; i <= N; i++){
            cin >> P[i];
        }
        myfile << "Case #" << k << ": " << ( N % 2 ) << endl;
        if( N % 2 ) myfile << "0.0" << endl;
    }
}
