#include <iostream>
#include <algorithm>
using namespace std;

int b, s, baches[10000 + 5], spins[10000 + 5], c = 0;

int main(){
    while(cin >> b >> s){
        if(!b & !s) return 0;
        for(int i = 0; i < b; i++){
            cin >> baches[i];
        }
        for(int i = 0; i < s; i++){
            cin >> spins[i];
        }
        printf("Case %d: %d", ++c, max(0, b-s));
        if(b-s > 0){
            sort(baches, baches + b);
            /*
            cout << endl;
            for(int i = 0 ; i < b; i++){
                cout << baches[i] << endl;
            }
            cout << endl;
            */
            printf(" %d\n", baches[0]);
        } else {
            printf("\n");
        }
    }
}
