#include <iostream>
#include <string.h>
using namespace std;

string words[836810 + 10], query;

void genWords(){
    int index = 0;
    for(index = 0; index < 26; index++){
        words[index] = index + 'a';
        //cout << index << ": " << words[index] << endl;
    }

    for(int i = 0; index <= 83680; i++){
        char ll = words[i][words[i].length() - 1];
        //cout << "last letter of " << words[i] << " is " << ll << ". ";
        for(int j = ll - 'a' + 1; j < 26; j++){
            char z = j + 'a';
            //cout << "adding: " << z << endl;
            words[index] = words[i] + z;
            //cout << index << ": " << words[index] << endl;
            index++;
        }
    }
}

bool isLex(string s){
    int l = s.length();
    for(int i = 1; i < l; i++){
        if(s[i-1] >= s[i]) return false;
    }
    return true;
}

int main(){
    genWords();
    while(cin >> query){
        if(isLex(query)){
            for(int i = 0 ; i < 83681; i++){
                if(words[i] == query){
                    printf("%d\n", i + 1);
                    break;
                }
            }
        } else {
            printf("0\n");
        }
    }
}
