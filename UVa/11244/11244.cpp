#include <iostream>
#include <string.h>
using namespace std;

char sky[105][105], a, b, stars;
bool flag;
string s;

int main(){
    while(cin >> a >> b){
        cout << "a = " << a << ", b = " << b << endl;
        if(!a && !b) return 0;
        stars = 0;
        for(int i = 0 ; i <= a + 1; i++){
            for(int j = 0 ; j <= b + 1; j++){
                sky[i][j] = '.';
            }
        }
        //cout << "a = " << a << endl;
        for(int i = 0; i < a; i++){
            cin >> s;
            cout << "i < a: " << i << " < " << a << ": " << (i < a) << endl;
            for(int j = 1 ; j <= b; j++){
                sky[i+1][j] = s[j-1];
            }
        }
        for(int i = 1; i <= a; i++){
            for(int j = 1 ; j <= b; j++){
                if(sky[i][j] == '*'){
                    flag = true;
                    for(int k = -1; k <= 1; k++){
                        for(int l = -1; l <= 1; l++){
                            if(k != 0 || l != 0 && sky[a + l][b + k] == '*'){
                                flag = false;
                                break;
                            }
                        }
                    }
                    stars += flag;
                }
            }
        }
        cout << stars << endl;
    }
}
