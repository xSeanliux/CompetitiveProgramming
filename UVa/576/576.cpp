#include <iostream>
#include <string.h>
using namespace std;

string s;

bool isVowel(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

int main(){
    while(getline(cin, s)){
        if(s == "e/o/i") return 0;
        s += 'x'; //does not affect no. of syllables
        int currentLine = 1, syls = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '/' || i == s.length() - 1){
                //cout << syls << " syllables in line " << currentLine << endl;
                if((currentLine % 2 && syls != 5) || (currentLine == 2 && syls != 7)){
                    cout << currentLine << endl;
                    break;
                } else if(i == s.length() - 1){
                    cout << "Y" << endl;
                }
                currentLine++;
                syls = 0;
            }
            if(isVowel(s[i])){
                syls++;
                while(isVowel(s[i])) i++;
                i--;
            }
        }
    }
}
