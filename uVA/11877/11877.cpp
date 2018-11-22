#include <iostream>
using namespace std;
int emptyBottles, haveDrank;

int main(){
    while(cin >> emptyBottles){
        if(!emptyBottles) return 0;
        haveDrank = 0;
        int r;
        while(emptyBottles >= 3){
            //cout << "I've " << emptyBottles << " bottles " << endl;
            r = emptyBottles % 3;
            emptyBottles -= r;
            emptyBottles /= 3;
            //cout << "Swap and drink " << emptyBottles << " bottles " << endl;
            haveDrank += emptyBottles;
            emptyBottles += r;

        }
        if(emptyBottles == 2){
            haveDrank++;
        }
        cout << haveDrank << endl;

    }

}
