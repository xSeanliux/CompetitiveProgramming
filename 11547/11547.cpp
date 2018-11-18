#include <iostream>
#include <math.h>
using namespace std;

int N;
/*11547
int main(){
    while(cin >> N){
        for(int i = 0 ; i < N; i++){
            double n;
            cin >> n;
            double ans = ((((567*n)/9)+7492)*235/47)-498;
            if(ans >= 0){
                cout << ((int)floor(ans/10))%10 << endl;
            } else {
                cout << (abs((int)ceil(ans/10)))%10 << endl;
            }


        }
    }
}
*/

//11172

int main(){
    int a, b;
    while(cin >> N){
        for(int i = 0; i < N; i++){
            cin >> a >> b;
            if(a > b){
                cout << ">" << endl;
            } else if(a == b) {
                cout << "=" << endl;
            } else {
                cout << "<" << endl;
            }

        }
    }
}



