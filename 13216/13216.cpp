#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int k;
string h;
int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> h;
        if(h == "0"){
            cout << 1 << endl;
            continue;
        } else if(h == "1"){
            cout << 66 << endl;
            continue;
        }
        int l = h.length();
        h = h.substr(l-1);
        int N = stoi(h) % 5;
        if(!N){
            cout << 76 << endl;
            continue;
        } else if(N == 1){
            cout << 16 << endl;
            continue;
        }
        cout << (long long int)pow(66, N + 0.0) % 100 << endl;


    }
}

