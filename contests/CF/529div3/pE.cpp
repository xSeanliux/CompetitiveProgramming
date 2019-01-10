#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
string s;

int main(){
    cin >> N >> s;
    int nO[N + 2], nC[N + 2];//no. Open, No. Closed
    if(s[0] == ')'){
        nC[0] = 1;
        nO[0] = 0;
    } else {
        nO[0] = 1;
        nC[0] = 0;
    }
    for(int i = 1; i < N; i++){
        nC[i] = nC[i-1];
        nO[i] = nO[i-1];
        if(s[i] == ')'){
            nC[i]++;
        } else {
            nO[i]++;
        }
    }
    for(int i = 0; i < N; i++){
        cout << nO[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << nC[i] << " ";
    }
    if(abs(nO[N-1] - nC[N-1]) != 2){
        cout << 0 << endl;
        return 0;
    }
    int ans1 = 0;
    if(nO[N-1] > nC[N-1]){ //turn ( into ) - O - 1, C + 1
        for(int i = 0; i < N; i++){
            if(nO[i] - 1 < nC[i] + 1){
                ans1 = 0;
            } else if(s[i] == '(' && i != 0) ans1++;
        }
    } else {
        for(int i = 0; i < N; i++){
            if(nO[i] + 1 < nC[i] - 1){
                ans1 = 0;
            } else if(s[i] == ')' && i != N-1) ans1++;
        }
    }
    reverse(s.begin(), s.end());
    if(s[0] == '('){
        nC[0] = 1;
        nO[0] = 0;
    } else {
        nO[0] = 1;
        nC[0] = 0;
    }
    cout << s << endl;
    for(int i = 1; i < N; i++){
        nC[i] = nC[i-1];
        nO[i] = nO[i-1];
        if(s[i] == '('){
            nC[i]++;
        } else {
            nO[i]++;
        }
    }
    for(int i = 0; i < N; i++){
        cout << nO[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < N; i++){
        cout << nC[i] << " ";
    }
    int ans2 = 0;
    if(nO[N-1] > nC[N-1]){ //turn ( into ) - O - 1, C + 1
        for(int i = 0; i < N; i++){
            if(nO[i] - 1 < nC[i] + 1){
                ans2 = 0;
            } else if(s[i] == ')' && i != 0) ans2++;
        }
    } else {
        for(int i = 0; i < N; i++){
            if(nO[i] + 1 < nC[i] - 1){
                ans2 = 0;
            } else if(s[i] == '(' && i != N-1) ans2++;
        }
    }
    cout << min(ans1, ans2) << endl;
}
