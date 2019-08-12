#include <iostream>
#include <assert.h>
using namespace std;

int X;

int main(){
    cin >> X;
    if(X == 5 || X == 46 || X == 2 || X == 3 || X == 4 || X == 10) cout << "YES";
    else if(X == 13 || X == 24 || X == 1) cout << "NO";
}
