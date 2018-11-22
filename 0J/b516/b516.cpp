#include <iostream>
using namespace std;

int main(){
    int N;
    char str[15]; //max 12
    while(cin >> N){
        for(int i = 0 ; i < N ; i++){
            cin >> str;

            cout << "received: " << str << endl;
            for(int i = 0 ; i < str.length() ; i++){
                str[i] = (str[i]+3)%26;
                cout << (str[i]+3)%26 + 'A' << endl;
            }
            cout << str << endl;
        }
    }


}
