#include <iostream>
#include <string>
using namespace std;

int main(){
    string currentStr;
    char str[1000], sub[1000];
    while(cin >> sub >> str){
        for(int i = 0 ; i < strlen(str); i++){
            for(int j = 0; j < strlen(str); j++){
                if(sub[i] == str[j]){
                    cout << sub[i] << " found. " << endl;
                    i = j;
                    currentStr += sub[i];
                    if(strcmp(sub, currentStr) == 0){
                        cout << "Yes" << endl;
                        break;
                    }
                } else if( j == strlen(str)-1) {
                    cout << "No" << endl;
                    break;
                }
            }
        }
    }

}
