#include <iostream>
using namespace std;
bool standing[2000000000];//max 2000000000
int main(){

    int people = 0, times;
    while(cin >> people >> times){
        int sum = 0;

        for(int i = 0; i < people; i++){
            standing[i] = true;
        }
        int start, fin;
        for(int i = 0; i < times; i++){
            cin >> start >> fin;
            for(int j = start-1; j < fin; j++){
                standing[j] = !standing[j]; //Not gate

            }

        }

        for(int i = 0; i < people; i++){
            if(standing[i]) sum++;
        }
        cout << sum << endl;
        sum = 0;

    }

}
