#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int n, m;
    registerGen(argc, argv, 1);
    n = rnd.next(2, 1000);
    m = rnd.next(2, 1000);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << rnd.next(-100000, 0) << " ";
        }
        cout << endl;
    }
}
