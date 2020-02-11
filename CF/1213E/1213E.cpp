#include <iostream>
#include <string.h>
using namespace std;

string s, t;
int n;

int main(){
    cin >> n >> s >> t;
    cout << "YES" << endl;
    if(s[0] == s[1] && t[0] == t[1]){ //great!
        for(int i = 0; i < n; i++){
            cout << "abc";
        }
        cout << endl;
        return 0;
    } else if(s[0] == s[1]){//the problem is with t
        if(t == "ab" || t == "bc" || t == "ca"){
            for(int i = 0; i < n; i++){
                cout << "acb";
            }
        } else {
            for(int i = 0; i < n; i++){
                cout << "abc";
            }
        }
        cout << endl;
    } else if(t[0] == t[1]){
        if(s == "ab" || s == "bc" || s == "ca"){
            for(int i = 0; i < n; i++){
                cout << "acb";
            }
        } else {
            for(int i = 0; i < n; i++){
                cout << "abc";
            }
        }
        cout << endl;
    } else {
        int cnt = 0;
        char arr[2];
        if(s[0] == t[0]){
            for(int i = 0; i < 3; i++){
                if((char)(i + 'a') == s[0]) continue;
                else arr[cnt++] = (i + 'a');
            }
            for(int i = 0; i < 2 * n; i++){
                cout << arr[i % 2];
            }
            for(int i = 0; i < n; i++){
                cout << s[0];
            }
            cout << endl;
        } else if(s[1] == t[1]){
            for(int i = 0; i < 3; i++){
                if((char)(i + 'a') == s[1]) continue;
                else arr[cnt++] = (i + 'a');
            }
            for(int i = 0; i < n; i++){
                cout << s[1];
            }
            for(int i = 0; i < 2 * n; i++){
                cout << arr[i % 2];
            }
            cout << endl;
        } else if(s[0] == t[1] && s[1] == t[0]){
            char c;
            for(char i = 'a'; i <= 'c'; i++){
                if(i != s[0] && i != s[1]) c = i;
            }
            for(int i = 0; i < n; i++){
                cout << s[0];
            }
            for(int i = 0; i < n; i++){
                cout << c;
            }
            for(int i = 0; i < n; i++){
                cout << s[1];
            }
        } else {
            if(t == "ab" || t == "bc" || t == "ca" || s == "ab" || s == "bc" || s == "ca"){
                for(int i = 0; i < n; i++){
                    cout << "acb";
                }
            } else {
                for(int i = 0; i < n; i++){
                    cout << "abc";
                }
            }
            cout << endl;
        }
    }
}
