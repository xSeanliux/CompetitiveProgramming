#include <iostream>
#include <math.h>
using namespace std;

const int maxN = 2e5;
int POS[maxN + 10], x, N;
char c;

int main(){
    cin >> N;
    int L = 0, R = 1;
    for(int i = 0; i < N; i++){
        cin >> c >> x;
        if(c == 'L'){
            POS[x] = L--;
        } else if(c == 'R'){
            POS[x] = R++;
        } else {
            cout << min(abs(POS[x] - L), abs(POS[x] - R)) - 1 << endl;
        }
    }
}
