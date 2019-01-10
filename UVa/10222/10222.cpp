#include <iostream>
using namespace std;

char arr[256];
string dict = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./", s;

int main(){
    for(int i = 0 ; i < 256; i++)
        arr[i] = (char)i;
    for(int i = 2 ; i < dict.length(); i++){
        arr[dict[i]] = dict[i-2];
    }
    while(getline(cin, s)){
        int l = s.length();
        for(int i = 0; i < l; i++){
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 'a' - 'A';
            cout << arr[s[i]];
        }
        cout << endl;
    }
}
