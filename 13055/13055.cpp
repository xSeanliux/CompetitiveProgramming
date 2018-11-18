#include <iostream>
#include <string.h>
using namespace std;


string stk[1000000];
string com, arg;
int head, c;

int main(){
    head = 0;
    cin >> c;
    for(int k = 0 ; k < c; k++){
        cin >> com;
        if(com == "Test"){
            if(head){
                cout << stk[head-1] << endl;
            } else {
                cout << "Not in a dream" << endl;
            }
        } if(com == "Kick" && head){
            head--;
        } else if (com == "Sleep") {
            cin >> arg;
            stk[head] = arg;
            head++;
        }
    }
}
