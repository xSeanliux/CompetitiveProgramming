
#include <iostream>
using namespace std;
int main(){
    int x, steps;
    while( cin >> x ){
            counter = 0;
        while(x > 1){

            if(x % 2 == 1){
                x -= 1;
                x /= 2;

            } else {
                x /= 2;
            }


            steps++;

        }

        cout << ++steps << endl;
    }

}
