#include <iostream>
#include <string>
using namespace std;

int main(){
    int N, a, b, c, d, e;
    while(cin >> N){
        for(int i = 0 ; i < N; i++){
            cin >> a >> b >> c >> d >> e;
            int starttime = a*60 + b;
            int endtime = c * 60 + d;
            if(starttime + e <= endtime){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}
