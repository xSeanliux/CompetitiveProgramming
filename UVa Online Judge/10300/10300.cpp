
#include <iostream>
using namespace std;

int a, b, c;
int cases, tests;
int sum;
int main(){
    cin >> cases;
    for(int i = 0; i < cases; i++){
        cin >> tests;
        sum = 0;
        for(int j = 0; j < tests; j++){
            cin >> a >> b >> c; //area, animals, eco
            sum += a * c;
        }
        cout << sum << endl;
    }
}

/*

1 7 5 6 2
2 6 5 7 1

1 8 9 3
3 9 8 1




*/
