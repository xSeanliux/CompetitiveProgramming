#include <iostream>
using namespace std;

int cases, len;
int wallH[100];
int main(){
    cin >> cases;
    for(int dd = 1; dd <= cases; dd++){
        int h = 0, l = 0;
        cin >> len;

        for(int i = 0; i < len; i++){
            cin >> wallH[i];
        }
        for(int i = 1; i < len; i++){
            if(wallH[i] > wallH[i-1]){
                h++;
            } else if(wallH[i] < wallH[i-1]){
                l++;
            }
        }
        cout << "Case " << dd << ": " << h << " " << l <<endl;

    }
}
