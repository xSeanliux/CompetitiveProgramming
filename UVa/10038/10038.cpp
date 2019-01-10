#include <iostream>
#include <math.h>
using namespace std;

bool diffs[3000];
int N;

int main(){
    int a, b;
    bool canGo;
    while(cin >> N){
        cin >> a;
        canGo = true;
        for(int i = 1; i < N; i++){
            diffs[i] = false;
        }
        for(int i = 1; i < N; i++){
            cin >> b;
            if(!diffs[abs(a-b)]){
                diffs[abs(a-b)] = true;
            } else{
                canGo = false;
            }
            swap(a, b);
        }
        if(canGo){
            cout << "Jolly" << endl;
        } else {
            cout << "Not jolly" << endl;
        }


    }
}
