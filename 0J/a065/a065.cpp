#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
using namespace std;
int main(){
    string text;
    int password;
    while(cin >> text){
        for(int i = 1; i < 7; i++){
            password += abs(text[i] - text[i-1]);
            password *= 10;
        }
        password /= 10;
        cout << password << endl;
    }
}
