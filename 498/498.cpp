#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long int cr[500], x[500], b[500];
string str;
int main()
{
    while(getline(cin, str)){ //parse coefficients
        //cout << "CO: " << str << ", l :" << str.length() << endl;
        for(int i = 0; i < 500; i++){
            cr[i] = x[i] = 0;
        }
        int l = str.length();
        int chead = 0;
        string cS = "";
        for(int i = 0; i < l; i++){
            if(str[i] == ' '){
                if(cS != ""){
                    cr[chead] = stoi(cS);
                    chead++;
                    cS = "";
                } else {
                    continue;
                }
            } else {
                cS += str[i];
                if(i == l-1 && cS != ""){
                    cr[chead] = stoi(cS);
                    chead++;
                    cS = "";
                    //cout << x[chead] << endl;
                }

            }
        }
        //cout << "Chead: " << chead << endl;
        int c[chead];
        for(int i = 0; i <= chead-1; i++){
            c[i] = cr[chead - i - 1];
            //printf("c[%d]: %d", i, c[i]);
        }
        //parse x0s
        getline(cin, str);
        //cout << "X: " << str << endl;
        l = str.length();
        int xhead = 0;
        for(int i = 0; i < l; i++){
            if(str[i] == ' '){
                if(cS != ""){
                    x[xhead] = stoi(cS);
                    xhead++;
                    cS = "";
                } else {
                    continue;
                }

            } else {
                cS += str[i];
                if(i == l-1 && cS != ""){
                    x[xhead] = stoi(cS);
                    xhead++;
                    cS = "";
                    //cout << x[chead] << endl;
                }
            }
        }
        int deg = chead-1;
        for(int i = 0; i < xhead; i++){
            b[deg] = c[deg];
            //cout << b[chead-1] << endl;
                for(int j = deg-1; j >= 0; j--){
                b[j] = c[j] + b[j+1]*x[i];
                //cout << "b[" << j << "] = " << b[j] << endl;
            }

            if(i != 0){
                cout << " ";
            }
            cout <<  b[0];
        }
        cout << endl;

    }
    return 0;
}
