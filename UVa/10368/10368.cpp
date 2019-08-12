#include <iostream>
#include <vector>
using namespace std;

int A, B;
bool win[100000];

int main(){
    while(cin >> A >> B){
        if(!(A | B)) return 0;
        int SG = 0;
        if(B > A) swap(A, B);
        vector<int> piles;
        piles.clear();
        while(B){
            //cout << A / B << endl;
            piles.push_back(A/B);
            A %= B;
            swap(A, B);
        }
        //cout << endl;
        bool wantWin = 1; //0 for first, 1 for last
        win[piles.size() - 1] = 0;
        for(int i = piles.size() - 2; i >= 0; i--){
            if(piles[i] == 1) win[i] = !win[i + 1];
            else win[i] = 0;
            //cout << win[i] << endl;
        }
        if(!win[0]){
            cout << "Stan wins" << endl;
        } else {
            cout << "Ollie wins" << endl;
        }
    }
}
