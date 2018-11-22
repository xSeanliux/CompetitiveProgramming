#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

string s;
int c;

int convertToDec(string s){
    return 26*26*(s[0]-'A') + 26*(s[1]-'A') + (s[2]-'A');
}


int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> s;
        string L = s.substr(0, 3);
        string D = s.substr(4);
        if(abs(convertToDec(L) - stoi(D)) <= 100){
            printf("nice\n");
        } else {
            printf("not nice\n");
        }
    }
}
