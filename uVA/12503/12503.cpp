#include <iostream>
#include <string.h>
using namespace std;

int c, l, currentPos;
int commands[100 + 5];
string com, a1, a2;

int main(){
    cin >> c;
    for(int k = 0; k < c; k++){
        cin >> l;
        currentPos = 0;
        for(int jj = 1; jj <= l; jj++){
            cin >> com;
            if(com == "SAME"){
                cin >> a1 >> a2;
                commands[jj] = commands[stoi(a2)];
            } else {
                commands[jj] = (com == "RIGHT") ? 1 : -1;
            }
        }
        for(int jj = 1; jj <= l; jj++){
            currentPos += commands[jj];
        }
        cout << currentPos << endl;
    }
}
