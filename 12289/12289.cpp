#include <iostream>
#include <string>
using namespace std;

int n;
string s;
int main(){
    cin >> n;
        for(int i = 0 ; i < n; i++){
            cin >> s;
            if(s.length() == 5){
                cout << 3 << endl;
            } else {
                int m = 0;
                m = (s[0] == 'o') + (s[1] == 'n') + (s[2] == 'e');
                if(m >= 2){
                    cout << 1 << endl;
                } else {
                    cout << 2 << endl;
                }
            }
        }

}
