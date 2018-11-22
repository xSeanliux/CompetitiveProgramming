#include <iostream>
#define MAX 1000000000
using namespace std;

int divs[1000000005];

void buildTable(){
    for(long long int i = 1; i <= MAX/2; i++){
        cout << "i = " << i << endl;
        long long int _i = i;
        while(_i <= MAX){
            divs[i]++;
            _i += i;
        }
    }
}


int main(){
    buildTable();
    cout << "End" << endl;
}
