#include <iostream>
using namespace std;

int c, L, M, N;

int main(){
    cin >> c;
    int total;
    for(int ia = 0; ia < c; ia++){
        cin >> L >> M >> N;
        total = 0;
        M += L;
        L = 0;
        //drink
        while(L + M >= N){
            M += L;
            //cout << "Drink " << L << " sodas" << endl;

            L = (M - M%N) / N;
            total += L;
            //cout << "I have " << M << " empty bottles, and " << N << " per new soda, so now I have " << L << " sodas" << endl;
            M %= N;
            //cout << "and " << M << " empty bottles remaining " << endl;
        }
        printf("%d\n", total);

    }
}
