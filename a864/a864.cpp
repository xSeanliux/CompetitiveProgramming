#include <iostream>
using namespace std;

int main(){
    string name;
    double B, V;
    while(cin >> name){
        if(name == "END") return 0;
        else {
            cin >> B >> V;
            cout << name;
            double B_V = B - V;
            printf(" %.2f ", B_V);
            if(-0.350 <= B_V && -0.251 >= B_V ){
                cout << "O" << endl;
            } else if(-0.250 <= B_V && -0.001 >= B_V ){
                cout << "B" << endl;
            } else if(0 <= B_V && 0.249 >= B_V ){
                cout << "A" << endl;
            } else if(0.250 <= B_V && 0.499 >= B_V ){
                cout << "F" << endl;
            } else if(0.500 <= B_V && 0.999 >= B_V ){
                cout << "G" << endl;
            } else if(1.000 <= B_V && 1.499 >= B_V ){
                cout << "K" << endl;
            } else if(1.500 <= B_V && 2.000 >= B_V ){
                cout << "M" << endl;
            }

        }
    }
}
