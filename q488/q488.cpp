#include <iostream>
using namespace std;

int drawPyramid(int height){
    for(int i = 1; i <= height; i++){

        for(int j = 0; j < i; j++){
            cout << i;
        }
        cout << endl;

    }

    for(int i = height-1; i > 0; i--){

        for(int j = 0; j < i; j++){
            cout << i;
        }
                cout << endl;



    }

}



int main(){
    int height, amount, cases;
    while( cin >> cases){

        for(int i = 0; i < cases; i++){
            cin >> height >> amount;
            for(int j = 0; j < amount; j++){
                    drawPyramid(height);
                    if(i != cases-1 | j != amount-1)
                    cout << endl;
            }
        }
    }


}
