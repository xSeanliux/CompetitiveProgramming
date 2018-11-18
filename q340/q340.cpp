#include <iostream>
#include <string.h>
using namespace std;

bool visitedStr[1005];
bool visitedAns[1005];
int N;
string ans, currentStr;

void f(string str){
    for(int i = 0; i < 2*N; i++){
        visitedStr[i] = false;
        visitedAns[i] = false;
    }
    int A = 0;
    int B = 0;
    //cout << "Comparing " << str << " with " << ans << endl;
    for(int i = 0; i < 2*N; i += 2){
        if(str[i] == ans[i]){
            A++;
            B--;
        }
        for(int j = 0 ; j < 2*N; j += 2){
            if(str[i] == ans[j] && !visitedAns[j] && !visitedStr[i] ){
                B++;
                visitedAns[j] = true;
                visitedStr[i] = true;
            }

        }
    }
    cout << "    (" << A << "," << B << ")" << endl;
}


string t;
int main(){
    int games = 1;
    bool flag;
    while(cin >> N){
        flag = true;
        if(N == 0){
            cout << endl;
            return 0;

        }
        getline(cin, t);
        getline(cin, ans);
        cout << "Game " << games << ":" << endl;
        while(getline(cin, currentStr)){
            int zeroes = 0;
            for(int i = 0; i < 2*N; i+=2){
                if(currentStr[i] == '0'){
                    zeroes++;
                }
            }
            if(zeroes == N){
                flag = false;
                break;

            }
            f(currentStr);
        }
        games++;
        if(flag){
            cout << endl;
        }
    }

}
