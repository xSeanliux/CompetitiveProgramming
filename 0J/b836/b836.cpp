#include <iostream>
using namespace std;
int main(){
    long long int petals, diff;
    while(cin >> petals >> diff){
        if(diff == 0){
            cout << "Go Kevin!!" << endl;
            continue;
        }
        int i = 1;
        while(petals > 0){
            petals -= i;
            i += diff;
            //cout << petals << endl;
        }
        if(petals == 0){
            cout << "Go Kevin!!" << endl;
        } else {
            cout << "No Stop!!" << endl;
        }
    }
}
