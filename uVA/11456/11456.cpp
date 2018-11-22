#include <iostream>
#include <algorithm>
using namespace std;

int a[3], cases;
int main(){
    cin >> cases;
    for(int i = 1; i <= cases; i++){
            cin >> a[0] >> a[1] >> a[2];
            sort(a, a+3);
            cout << "Case " << i << ": " << a[1] << endl;

    }

}
