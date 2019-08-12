#include <iostream>
#include <string>
#include <vector>
#include <sstream> //this is pretty important
using namespace std;

string s;
int T, n, sum;
vector<int> vec;

int main(){
    scanf("%d", &T);
    getline(cin, s);
    while(T--){
        getline(cin, s);
        sum = 0;
        vec.clear();
        istringstream is(s);
        while(is >> n){
            vec.push_back(n);
            sum += n;
        }
        if(sum % 2){
            printf("NO\n");
            continue;
        }
        bool dp[sum + 1];
        for(int i = 0; i <= sum; i++) dp[i] = false;
        dp[0] = true;
        for(int t : vec){
            for(int i = sum - t; i >= 0; i--){
                if(dp[i]) dp[i + t] = true;
            }
        }
        if(dp[sum/2]){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
