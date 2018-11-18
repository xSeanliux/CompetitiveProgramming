#include <iostream>
#include <math.h>
using namespace std;

int m, n, c;

int main()
{
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> m >> n;
        int k = ceil((m-2)/3.0);
        int l = ceil((n-2)/3.0);
        cout << k * l << endl;
    }
}
