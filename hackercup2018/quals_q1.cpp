#include <iostream>
#include <string>
#include <fstream>
using namespace std;

long long int c, N, K, V;
string arr[50 + 5];
int main(){
    ofstream myfile;
    myfile.open ("output.txt");
    cin >> c;
    for(int cn = 1; cn <= c; cn++){
        cin >> N >> K >> V;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        int indices[K + 5];
        int R = ((V%N) * (K%N)) % N;
        if(!R) R = N;
        for(int i = 0 ; i < K; i++){
            if(!(R)) R = N;
            indices[i] = (R) ? R : N-1;
            //cout << R << endl;
            R--;

        }
        myfile << "Case #" << cn <<": ";
        sort(indices, indices + K);
        for(int i = 0 ; i < K; i++){
            myfile << arr[indices[i] - 1] << " ";
            cout << arr[indices[i] - 1] << " ";
        }
        myfile << endl;

    }
}
