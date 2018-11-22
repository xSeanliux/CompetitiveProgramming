#include <iostream>
using namespace std;
bool isDead[1000007]; //max 10^6
int main(){
    int people, cases, M;
    while(cin >> people >> cases){
        for(int i = 0; i < people; i++){
            isDead[i] = false;
        }
        for(int j = 0; j < cases; j++){
            cin >> M;
            for(int i = M+1; i <= people+1; i++){
            //cout << "Checking: " << i << endl;
            if(i > people){ //out of range!
                cout << "0u0 ...... ?" << endl;
                break;
            }else if(!isDead[i]){
                cout << i << endl;
                isDead[i] = true;
                break;
            }
        }
        }

    }


}
