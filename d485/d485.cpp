#include <iostream>
using namespace std;

int main(){
    int start, fin;
    while(cin >> start >> fin){
        start += start%2;
        fin -= fin%2;
        cout << (fin-start)/2+1 << endl;
    }

}
