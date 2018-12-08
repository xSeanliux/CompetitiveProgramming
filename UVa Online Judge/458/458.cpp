#include <iostream>
#include <string>
using namespace std;

string query;

int main(){
    while(getline(cin, query)){
        for(int i = 0; i < query.length(); i++){
            cout << (char)(query[i]-7);
        }
        cout << endl;
    }
}

