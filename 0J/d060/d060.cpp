#include <iostream>
using namespace std;
int main(){
    int minute;
    while(cin >> minute){
        cout << (85-minute) % 60 << endl;
    }
}
