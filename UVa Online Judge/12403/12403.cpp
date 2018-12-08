#include <iostream>
#include <string>
using namespace std;


string command;
int n, total, c;

int main(){
    cin >> c;
    total = 0;
    for(int i = 0; i < c; i++){
        cin >> command;
        if(command[0] == 'r'){
            cout << total << endl;
        } else {
            cin >> n;
            total += n;
        }
    }
}
