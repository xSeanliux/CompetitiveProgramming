#include <iostream>
using namespace std;


int N, ones, zeroes, x;

bool vals[(int) 2e5];

int main(){
    cin >> N;
    ones = 0; zeroes = 0;
    for(int i = 0; i < N; i++){
        cin >> vals[i];
        if(vals[i] == 1) ones++;
        else zeroes++;
    }
    int cntz = 0, cnto = 0;
    for(int i = 0; i < N; i++){
        if(vals[i] == 1) cnto++;
        else cntz++;
        if(cntz == zeroes || cnto == ones){
            cout << i + 1 << endl;
            return 0;
        }
    }
}
