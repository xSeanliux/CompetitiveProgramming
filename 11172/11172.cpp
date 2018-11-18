#include <iostream>
using namespace std;


int a, b, c;

int main(){
    cin >> c;
    for(int i = 0; i < c; i++){
        cin >> a >> b;
        if(a > b){
            cout << ">" << endl;
        } else if(a < b){
            cout << "<" << endl;
        } else {
            cout << "=" << endl;
        }
    }
}
