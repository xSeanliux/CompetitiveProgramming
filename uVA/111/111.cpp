#include <iostream>
#include <string.h>
using namespace std;

string s;

int N, c;
int dp[20 + 5][20 + 5];
string ans[20 + 5], current[20 + 5];
string _t;

void parse(string s, string arr[]){
    string cS = "";
    int head = 0;
    int l = s.length();
    for(int i = 0; i < l; i++){
        if(s[i] == ' '){
            int k = stoi(cS) - 1;
            arr[k] = to_string(++head);

            cS = "";
        } else {
            cS += s[i];
            if(i == l-1){
                int k = stoi(cS) - 1;
                arr[k] = to_string(++head);
                cS = "";
            }
        }
    }
}


int main(){
    while(getline(cin, s)){
        int p = 0, l = s.length();
        for(int i = 0 ; i < l; i++){
            if(s[i] == ' ') p++;
        }
        if(p == 0){
            N = stoi(s);
            c = 0;
            continue;
        }
        //if it's just a number then it's N; else it's a test case
        if(c == 0){
            parse(s, ans);
            c++;
        } else {
            parse(s, current);
            for(int i = 0; i < 25; i++){
                for(int j = 0; j < 25; j++){
                    dp[i][j] = 0;
                }
            }
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    if(ans[i] == current[j]){
                        dp[i+1][j+1] = dp[i][j] + 1;
                    } else {
                        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                    }
                }
            }
            printf("%d\n", dp[N][N]);
        }

    }
}
