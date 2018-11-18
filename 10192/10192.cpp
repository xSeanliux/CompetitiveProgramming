#include <iostream>
#include <string.h>
using namespace std;

string a, b;
int table[100 + 5][100 + 5];
int main(){
    int round = 1;
    while(getline(cin, a)){
        if(a[0] == '#'){
            return 0;
        } else {
            getline(cin, b);
        }
        for(int i = 0; i <= a.length(); i++){
            for(int j = 0; j <= b.length(); j++){
                table[i][j] = 0;
            }
        }
        for(int i = 1; i <= a.length(); i++){
            for(int j = 1; j <= b.length(); j++){
                if(a[i-1] == b[j-1]){
                    table[i][j] = table[i-1][j-1] + 1;
                } else {
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
        }
        cout << "Case #" << round << ": you can visit at most " << table[a.length()][b.length()] << " cities." << endl;
        round++;

    }
}
