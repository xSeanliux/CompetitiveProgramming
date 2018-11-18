#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
using namespace std;

string input;
int main(){
    while(getline(cin, input)){
        int len = input.length();
        int currentLen = 0;
        for(int i = 0;i < len; i++){

            if(input[i] - '0' < 10 && input[i] - '0' > 0){ //number
                currentLen += input[i] - '0';
            } else if(input[i] == '!'){
                cout << endl;
                currentLen = 0;
            } else if(input[i] == 'b') {
                for(int j = 0; j < currentLen; j++){
                    cout << " ";
                }
                currentLen = 0;
            } else if(input[i] == '\n' || input[i] == '\r'){
                cout << endl;
            }else {
                for(int j = 0; j < currentLen; j++){
                    cout << input[i];
                }
                currentLen = 0;
            }

        }

        cout << endl;


    }

}
