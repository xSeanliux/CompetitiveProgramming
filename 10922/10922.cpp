#include <iostream>
#include <string.h>
using namespace std;

int dsum;
string str;

int getDsums(string str){
    int r = 0;
    int l = str.length();
    for(int i = 0 ; i < l; i++){
        r += (str[i] - '0');
    }
    return r;
}

int getDsumi(int N){
    int r = 0;
    while(N > 0){
        r += N % 10;
        N -= N % 10;
        N /= 10;
    }
    return r;
}

int main(){
    while(cin >> str){
        if(str == "0") return 0;
        //cout << "STR :" << str << endl;
        int dsum = getDsums(str);
        if(dsum % 9 == 0){
            int c = 1;
            while(dsum > 10){
                dsum = getDsumi(dsum);
                c++;
            }
            cout << str << " is a multiple of 9 and has 9-degree " << c << "." << endl;

        } else {
            cout << str << " is not a multiple of 9." << endl;
        }
    }
}
