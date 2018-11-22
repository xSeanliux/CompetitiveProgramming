#include <iostream>
#include <string.h>
using namespace std;

string s;
int C;
//you should flush the output, by calling cout << flush or cout << flush in
//C/C++

int main(){
    cin >> C;
    while(C--){
        string ans = "";
        bool flag = false, ret;
        do{
            cout << "Ask " << (ans + '0') << endl;
            flush(cout);
            cin >> ret;
            if(ret){
                ans += '0';
                flag = true;
            } else {
                cout << "Ask " << (ans + '1') << endl;
                flush(cout);
                cin >> ret;
                if(ret){
                    ans += '1';
                    flag = true;
                } else {
                    flag = false; //time for theo ther direction
                }
            }
        } while(flag);
        flag = false;
        do{
            cout << "Ask " << ('0' + ans) << endl;
            cin >> ret;
            flush(cout);
            if(ret){
                ans = '0' + ans;
                flag = true;
            } else {
                cout << "Ask " << ('1' + ans) << endl;
                flush(cout);
                cin >> ret;
                if(ret){
                    ans = ans + '1';
                    flag = true;
                } else {
                    flag = false; //time for the other direction
                }
            }
        } while(flag);
        cout << "Answer " << ans << endl;
        flush(cout);
    }
}
