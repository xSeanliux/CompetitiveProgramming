#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <set>
#include <map>
using namespace std;

int y, b, r;
int main(){
    cin >> y >> b >> r;
    for(int i = y; i > 0; i--){
        if(i+1 <= b && i+2 <= r){
            cout << 3*i + 3 << endl;
            return 0;
        }
    }
}
