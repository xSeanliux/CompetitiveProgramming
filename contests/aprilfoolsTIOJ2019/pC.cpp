#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;

int N, cnt;
string s;
vector<string> expr;
vector<bool> vals;

bool eval(){
    //cout << "Running " << cnt << ", " << expr[cnt] << endl;
    bool res;
    if(expr[cnt][0] == 'x') {
        //cout << "return: " << vals[stoi(expr[cnt].substr(1, 100000))] << endl;
        return vals[stoi(expr[cnt++].substr(1, 100000))];
    } else if(expr[cnt] == "and"){
        cnt++;
        res = eval() & eval();
    } else if(expr[cnt] == "or") {
        cnt++;
        res = eval() | eval();
    } else if(expr[cnt] == "xor"){
        cnt++;
        res = eval() ^ eval();
    } else if(expr[cnt] == "nand"){
        cnt++;
        res = !(eval() & eval());
    } else if(expr[cnt] == "nor"){
        cnt++;
        res = !(eval() | eval());
    } else if(expr[cnt] == "nxor"){
        cnt++;
        res = !(eval() ^ eval());
    } else {
        cnt++;
        return !eval();
    }
    //cout << "res = " << (res ? "true" : "false") << endl;
    return res;
    //cout << "exit" << endl;
}

int main(){
    cin >> N;
    getline(cin , s);
    getline(cin, s);
    vals.reserve(N);
    int currentInd = 0; string cS = "";
    while(currentInd < s.length()){
        cS += s[currentInd++];
        if(s[currentInd] == ' ' || currentInd == s.length()){
            expr.push_back(cS);
            currentInd++;
            cS = "";
        }
    }
    //for(string st : expr) cout << st << endl;
    for(int i = 0; i < (1LL << N); i++){
        for(int j = 0; j < N; j++){
            vals[j] = (i & (1LL << j));
            //cout << "vals[" << j << "] = " << vals[j] << endl;
        }
        cnt = 0;
        if(!eval()){
            //cout << "FOund" << endl;
            for(int j = 0; j < N; j++) {
                cout << vals[j];
                if(j < N - 1) cout << endl;
            }
            return 0;
        }
    }
}
