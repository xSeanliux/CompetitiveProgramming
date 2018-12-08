#include <iostream>
#include <string.h>
using namespace std;

char step;
string num;
int a1, a2, b1, b2;

double rates[][3] = {
    {
        0.1, 0.06, 0.02
    },
    {
        0.25, 0.15, 0.05
    },
    {
        0.53, 0.33, 0.13
    },
    {
        0.87, 0.47, 0.17
    },
    {
        1.44, 0.8, 0.3
    }
}

int main(){
    while(cin >> step){
        if(step == '#') return 0;
        else {
            cin >> num >> a1 >> a2 >> b1 >> b2;
            //cout << step << " " << num << " " << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
            int minA = a1 * 60 + a2;
            int minB = b1 * 60 + b2;
            if(minA < minB){


            }
        }

    }

}
