#include <iostream>
using namespace std;

int main(){
    int N;
    while(cin >> N){
        if(N % 5 == 0){
                cout << "U" << endl;
        } else if(N % 5 == 1){
                cout << "G" << endl;
        } else if(N % 5 == 2){
                cout << "Y" << endl;
        } else if(N % 5 == 3){
                cout << "T" << endl;
        } else if(N % 5 == 4){
                cout << "I" << endl;
        }
    }

}
