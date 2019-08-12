#include <iostream>
#include <string.h>
using namespace std;

int T, dp[10000][10000];
string s;

bool match(char a, char b){
    return (a == '(' && b == ')') || (a == '[' && b == ']');
}

void godp(){
    for(int i = 0; i < s.length(); i++){
        dp[i][i] = 1;
        dp[i + 1][i] = 0; //out of bounds
    }
    for(int i = s.length() - 2; i >= 0; i--){
        for(int j = i + 1; j < s.length(); j++){
            dp[i][j] = s.length();
            if(match(s[i], s[j])) dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            for(int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
}

void print(int i, int j){
    //printf("Running print(%d, %d)\n", i, j);
    if(i > j) return;
    if(i == j){
        if(s[i] == '(' || s[i] == ')') printf("()");
        else printf("[]");
        return;
    }
    if(match(s[i], s[j]) && dp[i][j] == dp[i + 1][j - 1]){
        printf("%c", s[i]); print(i + 1, j - 1); printf("%c", s[j]);
        return;
    }
    for(int k = i; k < j; k++){
        if(dp[i][j] == dp[i][k] + dp[k + 1][j]){
            print(i, k);
            print(k + 1, j);
            return;
        }
    }
}

bool flag = true;

int main(){
    cin >> T;
    getline(cin, s);
    while(T--){
        getline(cin, s);
        getline(cin, s);
        godp();
        if(flag) flag = false;
        else printf("\n");
        print(0, s.length()-1);
        printf("\n");
    }
}
