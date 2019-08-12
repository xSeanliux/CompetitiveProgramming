#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <set>
using namespace std;


string a, b;

bool isVowel(char a){
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

int main(){
    cin >> a >> b;
    if(a.length() != b.length()){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < a.length(); i++){
        if(isVowel(a[i]) ^ isVowel(b[i])){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
