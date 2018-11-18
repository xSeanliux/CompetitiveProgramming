#include <iostream>
#include <string>
using namespace std;

int c = 1;
string input;
int main(){
    while(cin >> input){
        if(input == "*"){
            return 0;
        } else if(input == "Hajj"){
            cout << "Case " << c << ": ";
            cout << "Hajj-e-Akbar" << endl;
        } else {
            cout << "Case " << c << ": ";
            cout << "Hajj-e-Asghar" << endl;
        }
        c++;
    }

}
