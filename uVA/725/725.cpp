#include <iostream>
#include <string>
#include  <math.h>
using namespace std;

int currentChars[5], n, nAns, c = 0;
bool visited[10];

int Num(){
    int K = 0;
    for(int i = 0 ; i < 5; i++){
        K += currentChars[i] * pow(10, 4 - i);
    }
    return K;
}

bool isComplementary(int a, int b){
    string _a = to_string(a), _b = to_string(b);
    while(_a.length() < 5) _a = '0' + _a;
    while(_b.length() < 5) _b = '0' + _b;
    bool hasBeen[10];
    for(int i = 0; i < 10; i++){
        hasBeen[i] = false;
    }
    for(int i = 0 ; i < 5; i++){
        hasBeen[_a[i] - '0'] = true;
        hasBeen[_b[i] - '0'] = true;
    }
    for(int i = 0 ; i < 10; i++){
        if(!hasBeen[i])
            return false;
    }
    return true;

}


void dfs(int iteration){
    //cout << "running iteration " << iteration << endl;
    if(iteration == 5){ //exit
        int ret = Num();
        //cout << ret << endl;
        if(ret % n == 0){
            int ans = ret / n;
            if(isComplementary(ret, ans)){
                string _ret = to_string(ret), _ans = to_string(ans);
                while(_ret.length() < 5) _ret = '0' + _ret;
                while(_ans.length() < 5) _ans = '0' + _ans;
                cout << _ret << " / " << _ans << " = " << n << endl;
                nAns++;
            }
        }
    } else {
        for(int i = 0 ; i < 10; i++){
            if(!visited[i]){
                visited[i] = true;
                currentChars[iteration] = i;
                dfs(iteration + 1);
                visited[i] = false;
            }
        }
    }
}

int main(){
    while(cin >> n){
        if(!n) return 0;
        if(c)
            cout << endl;
        else
            c++;

        nAns = 0;
        dfs(0);
        if(!nAns)
            cout << "There are no solutions for " << n << "." << endl;
    }
}
