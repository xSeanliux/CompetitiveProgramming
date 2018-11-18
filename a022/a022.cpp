#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char str[1001];
    bool isPalindrome = true;

    while(cin >> str){
        isPalindrome = true;
        for(int i = 0; i < strlen(str)/2;  i++){
            //cout << "i: " << i << ", strlen-i: " << strlen(str) - i << endl;
            if(str[i]==str[strlen(str)-i-1] & isPalindrome){
                    //cout << str[i] << " != " << str[strlen(str)-i] << endl;
                    isPalindrome = true;



            } else {
                isPalindrome = false;
            }

        }
        switch(isPalindrome){
            case true: cout << "yes" << endl; break;
            case false: cout << "no" << endl; break;
        }


    }
}
