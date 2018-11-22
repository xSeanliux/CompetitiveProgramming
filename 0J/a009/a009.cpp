#include <iostream>
#include <string>
using namespace std;
int main(){
    string str = "", coded = "";
    while(cin >> str){
        coded = "";
        for(int i = 0; i < str.length(); i++){
            char _char = (int)str[i] - 7;

            coded += _char;
        }
        cout << coded << endl;
    }
}
//K = 7
