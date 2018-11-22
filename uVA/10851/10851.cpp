#include <iostream>
#include <string.h>
using namespace std;

string s;
char arr[10][80 + 5];
int c;

int main(){
    cin >> c;
    for(int k = 0 ; k < c; k++){
        string decoded = "";
        getline(cin , s);
        getline(cin , s);
        int l = s.length();
        for(int i = 0 ; i < l; i++){
            arr[0][i] = s[i];
        }
        for(int i = 1; i < 10; i++){
            cin >> s;
            for(int j = 0 ; j < l; j++){
                arr[i][j] = s[j];
            }
        }
        int val = 0;
        for(int i = 1; i < l-1; i++){
            for(int j = 8; j > 0 ; j--){
                val += (arr[j][i] == '\\');
                val *= 2;

            }
            cout << (char)(val/2);
            val = 0;
        }
        cout << endl;
        getline(cin , s);


    }
}
