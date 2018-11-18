#include <iostream>
using namespace std;

int c, DNA[10], density[42]; //0 and 41 are blank buffers

void output(){
    for(int i = 1 ; i <= 40; i++){
        if(density[i] == 0){
            cout << " ";
        } else if(density[i] == 1){
            cout << ".";
        } else if(density[i] == 2){
            cout << "x";
        } else {
            cout << "W";
        }
    }
    cout << endl;
}

void update(){
    int newDensity[42];
    fill(newDensity, newDensity + 42, 0);
    for(int i = 1; i <= 40; i++){
        newDensity[i] = DNA[density[i-1] + density[i] + density[i+1]];
        //cout << "newDenstiy[" << i << "] = " << newDensity[i] << endl;
    }
    for(int i = 1; i <= 40; i++){
        density[i] = newDensity[i];
    }

}

int main(){
    cin >> c;
    for(int ka = 0; ka < c; ka++){
        if(ka) cout << endl;
        for(int i = 0 ; i < 10; i++){
            cin >> DNA[i];
        }
        fill(density, density + 42, 0);
        density[20] = 1;
        for(int i = 0 ; i < 50; i++){
            output();
            update();
        }
    }
}

