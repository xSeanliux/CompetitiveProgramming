#include <iostream>
#include <string.h>
using namespace std;
string expression, a, b;
long long int C[51 + 5][51 + 5];
int k, p, c;
void getC(){
    C[0][0] = 0;
    C[1][0] = 1;
    C[1][1] = 1;
    for(int i = 1 ; i <= 50; i++){
        C[i][0] = 1;
        for(int j = 1; j < i; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
        C[i][i] = 1;
    }
}


int main(){
    getC();
    cin >> c;
    for(int kk = 1; kk <= c; kk++){
        cin >> expression;
        int l = expression.length();
        for(int i = 0 ; i < l; i++){
            if(expression[i] == '+'){
                a = expression.substr(1, i - 1);
                k = i;
            } else if(expression[i] == ')'){
                b = expression.substr(k+1, i - k - 1);
            } else if(expression[i] == '^'){
                p = stoi(expression.substr(i + 1));
            }
        }
        printf("Case %d: ", kk);
        if(p == 1){
            cout << a << "+" << b << endl;
            continue;
        }


        cout << a << "^" << p << "+";
        for(int i = p-1; i > 0; i--){
            cout << C[p][i] << "*" << a;
            if(i != 1){
                cout <<"^" << i;
            }

            cout << "*" << b;
            if(p - i != 1){
                cout << "^" << p-i;
            }
            cout << "+";
        }
        cout << b << "^" << p << endl;



        }

}
