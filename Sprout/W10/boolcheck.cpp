#include <iostream>
using namespace std;

int main(){
    bool vals[5];
    for(int i = 0; i < (1 << 3); i++){
        for(int j = 0; j < 3; j++){
            vals[j] = ((i & (1 << j)) > 0);
        }
        if((vals[0] | vals[1]) && (!vals[0] || vals[2]) && (!vals[1] || !vals[2]) && (!vals[0] || vals[1] || vals[2])){
            cout << vals[0] << " " << vals[1] << " " << vals[2] << endl;
        }
    }
}
