#include <iostream>
using namespace std;
int main(){
    int weight;
    while(cin >> weight){
        weight = (weight > 50) ? weight -1 : weight;
        cout << weight;
    }
}
