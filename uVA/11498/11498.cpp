#include <iostream>
#include <string.h>
using namespace std;
int N, a, b, rA, rB;
string s;
int main(){
    while(cin >> N){
        cin >> rA >> rB;
    //cout << rA << ", " << rB << endl;
        char t;
        for(int i = 0 ; i < N; i++){
            cin >> a;
            getline(cin, s);
            //cout << "STARTS" << s << "ENDS" << endl;
            if(s == "" || s == " " || s == "\n"){
              return 0;
            }
            b = stoi(s);

            if(a == rA || b == rB){
                cout << "divisa" << endl;
            } else if(a < rA){
                if(b > rB){
                    cout << "NO" << endl;
                } else {
                    cout << "SO" << endl;
                }
            } else {
                if(b  > rB){
                    cout << "NE" << endl;
                } else {
                    cout << "SE" << endl;
                }
            }
        }
    }

}
