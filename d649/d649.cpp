#include <iostream>
#include <string>
using namespace std;
int main(){
    int layers;
    string layer;
    while( cin >> layers){

        for(int i = 1; i < layers+1; i++){ //Iterating through every layer
                layer = " ";
                for(int j = 0; j < layers-i; j++){
                    layer.append("-");
                }
                for(int k = layers - i; k < layers; k++ ){
                    layer.append("+");
                }
                cout << layer << endl;

        }
    }
}
