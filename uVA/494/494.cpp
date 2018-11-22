#include <iostream>

#include <string>
using namespace std;

string query;

int main(){
    while(getline(cin, query)){
        int l = query.length();
        bool isInWord = false;
        int words = 0;
        for(int i = 0; i < l; i++){
            if('a' <= query[i] && query[i] <= 'z' || 'A' <= query[i] && query[i] <= 'Z'){
                isInWord = true;
            } else {
                if(isInWord){
                    words++;
                    isInWord = false;
                }
            }
        }
        cout << words << endl;
    }
}

