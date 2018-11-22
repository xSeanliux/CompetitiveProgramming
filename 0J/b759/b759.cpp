#include<iostream>
using namespace std;
string str;
int main(){
    while(cin >> str){
        for(int i = 0; i < str.length(); i++){
            for(int j = i; j < str.length()+i; j++){
                cout << str[j%str.length()];
            }
            cout << endl;
        }
    }


}
