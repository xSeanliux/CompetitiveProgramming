#include <iostream>
using namespace std;
int main(){
    int age, price = 0;
    while(cin >> age){
        price = 0;
        if(age >=  6) price += 590;
        if(age >= 12) price += 200;
        if(age >= 18) price += 100;
        if(age >= 60) price = 399;
        cout << price << endl;
    }
}
