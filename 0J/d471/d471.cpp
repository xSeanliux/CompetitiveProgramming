#include <iostream>
using namespace std;
bool num[20]; //max 14
int bytes;
void run(int iteration){
    if(iteration >= bytes){
        for(int i = 0 ; i < bytes; i++){
            cout << num[i];
        }
        cout << endl;
        return;
    } else {
        num[iteration] = 0;
        run(iteration+1);
        num[iteration] = 1;
        run(iteration+1);

    }
}

int main(){
    while(cin >> bytes){
        run(0);
    }
}
