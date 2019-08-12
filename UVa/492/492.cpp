#include <iostream>
#include <string.h>
using namespace std;

string s;

bool isVowel(char c){
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int main(){
    while(getline(cin , s)){
        string currentWord;
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])){
                currentWord = "";
                while(isalpha(s[i])){
                    currentWord += s[i];
                    i++;
                }
                i--;
                if(isVowel(toupper(currentWord[0]))){
                    currentWord += "ay";
                } else {
                    currentWord = currentWord.substr(1) + currentWord[0] + "ay";
                }
                cout << currentWord;
            } else {
                cout << s[i];
            }
        }
        cout << endl;
    }
}
