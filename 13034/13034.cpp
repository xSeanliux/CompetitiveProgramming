#include <iostream>
using namespace std;
int c, cI;

int main(){
    cin >> c;
    for(int ia = 1; ia <= c; ia++){
        printf("Set #%d: ", ia);
        bool flag = true;
        for(int i = 0 ; i < 13; i++){
            cin >> cI;
            if(!cI) flag = false;
        }
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
