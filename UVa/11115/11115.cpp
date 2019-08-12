#include <iostream>
#include <string.h>
#include <iomanip>
#include <math.h>
#define ll
using namespace std;

int N, D;



;
int main(){
    cout << fixed << setprecision(0);
    cout << "{" << endl;
    for(int i = 2; i <= 10; i++){
        cout << "\t{" << endl << "\t";
        for(int j = 1; j * log10(i) < 18 && j <= 25; j++){
            cout << pow(i, j) << ", ";
        }
        cout << endl << "\t}" << endl;
    }
    cout << "}" << endl;
    while(cin >> N >> D){

    }
}
