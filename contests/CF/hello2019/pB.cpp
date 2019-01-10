#include <iostream>
#include <string.h>
using namespace std;

bool current[360], nextArr[360];
int N, deg;

int mod(int A, int B){
    while(A < 0) A += B;
    return A % B;
}

int main(){
    cin >> N;
    memset(current, 0, 360);
    memset(nextArr, 0, 360);
    current[0] = 1;
    while(N--){
        cin >> deg;
        for(int i = 0; i < 360; i++){
            if(current[i]){
                nextArr[mod(i + deg, 360)] = 1;
                nextArr[mod(i - deg, 360)] = 1;
            }
        }
        swap(nextArr, current);
        memset(nextArr, 0, 360);
    }
    if(current[0]){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
