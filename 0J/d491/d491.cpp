#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int a, b, _tmp, sum = 0;
    while(cin >> a >> b){
        sum = 0;
        _tmp = a;
        a = max(a, b); //the bigger
        b = min(_tmp, b); // the smaller;
        a -= a%2; //to the nearest multiple of 2
        b += b%2; //same as above
        int numOfEvens = (a-b)/2;
        for(int i = b; i <= a; i+=2){
            sum += i;
        }
        cout << sum << endl;
    }
}

