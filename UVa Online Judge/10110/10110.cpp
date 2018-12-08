#include <iostream>
#include <math.h>
using namespace std;
long int N;
int main(){
    while(cin >> N){
        if(N){
            if(sqrt(N) == floor(sqrt(N))){
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else {
            return 0;
        }
    }

}
