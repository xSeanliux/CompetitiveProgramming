#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector <int> coeff, q;
int k;
string s;

int main(){
    while(cin >> k){
        coeff.clear();
        q.clear();
        getline(cin, s);
        getline(cin, s);
        int l = s.length();
        string cS = "";
        for(int i = 0; i < l; i++){
            if(s[i] == ' '){
                coeff.push_back(stoi(cS));
                cS = "";
                continue;
            }
            cS += s[i];
            if(i == l-1){
                coeff.push_back(stoi(cS));
            }
        }
        int currentNum = coeff[0];
        for(int i = 1; i <= coeff.size(); i++){
            q.push_back(currentNum);
            if(i == coeff.size())
                break;
            currentNum *= k;
            currentNum += coeff[i];
        }
        cout << "q(x):";
        for(int i = 0 ; i < q.size() - 1; i++){
            cout << " " << q[i];
        }
        printf("\nr = %d\n\n", q[q.size() - 1]);
    }
}


