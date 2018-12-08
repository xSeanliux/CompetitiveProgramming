#include <iostream>
#include <string.h>
using namespace std;

string str;
int N, D;

string f(string str, int N, int D, int cI){
    //cout << "Running: N = " << N << ", D = " << D << ", CI: " << cI <<  endl;
    if(D <= 0) return str;
    if(cI >= D){
        return str.substr(0, N-D);
    }
    char M = str[cI];
    for(int i = cI; i <= D+cI; i++){
        //cout << "Current Max; " << M << " current num: " << str[i] << endl;
        if(str[i] >= M){
            M = str[i];
        }
    }
    //cout << "Max: " << M - '0' << endl;
    int c = 0;
    for(int i = cI; i <= N-D+1; i++){
        //cout << "Checking: " << str[i] << endl;
        if(str[i] < M){
            //cout << "Deleting: " << str[i] << endl;
            str.erase(i, 1);
            i--;
            //cout << str << endl;
            c++;
        } else {
            break;
        }
    }
    if(c == 0) {
        cI++;
    }

    return f(str, N - c,D - c, cI);

}

int main(){
    string asdfasdf;
    while(cin >> N >> D){
        if(N == 0 && D == 0){return 0;}
        getline(cin, asdfasdf);
        getline(cin, str);
        str = f(str, N, D, 0);
        cout << str << endl;

    }

}

