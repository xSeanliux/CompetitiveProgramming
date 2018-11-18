#include <iostream>
#include <string.h>
#include <map>
using namespace std;

int C, N;
map<long long int, int>nthfib;
char plainText[105];
string s;

void initFib(){
    long long int dp[] = {1, 1, 2};
    nthfib.insert(pair<int, int>(1, 0));
    nthfib.insert(pair<int, int>(2, 1));
    int head = 2;
    for(int i = 0 ; i < 50; i++){ //43 is max
        dp[i%3] = dp[(i+1)%3] + dp[(i+2)%3];
        nthfib.insert(pair<int, int>(dp[i%3], head));
        head++;
    }
}

int main(){
    initFib();
    cin >> C;
    while(C--){
        cin >> N; //length of char

        memset(plainText, ' ', 105);
        int arr[N];
        for(int i = 0 ; i < N; i++)
            cin >> arr[i];
        getline(cin, s); //buffer
        getline(cin, s);
        //cout << "s: " << s << endl;
        string res = "";
        int l = s.length();
        int maxIndex = 0;
        for(int i = 0 ; i < l; i++){
            if(s[i] <= 'Z' && s[i] >= 'A')
                res += s[i];
        }
        //cout << "res: " << res << endl;
        s = res;
        for(int i = 0 ; i < N; i++){
            plainText[ nthfib[arr[i]] ] = res[i];
            //cout << "char " << res[i] << " goes in place " << nthfib[arr[i]] << endl;
            if(nthfib[arr[i]] > maxIndex)
                maxIndex = nthfib[arr[i]];
        }
        for(int i = 0 ; i <= maxIndex;  i++)
            cout << plainText[i];
        cout << endl;
    }
}
