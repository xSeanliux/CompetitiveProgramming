#include <iostream>
#include <string.h>

using namespace std;

string db[51];
string f(int k){
    return db[k];

}

int main(){
    int k, s, t;
    db[1] = "ABC";
    for(int i = 2; i < 51; i++){
        db[i] = "A" + db[i-1] + "B" + db[i-1] + "C";
        //cout << db[i] << endl;
    }
    cout << f(50) << endl;

}

