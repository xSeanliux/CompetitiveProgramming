#include <iostream>
#include <string>
using namespace std;

int N, C = 0;
string s;

int main(){
    cin >> N;
    while(N--){
        cin >> s;
        string ans = "";
        int l = s.length();
        for(int i = 0; i < l; i++){
            char c = s[i];
            i++;
            string _s = "";
            while(s[i] <= '9' && s[i] >= '0'){
                _s += s[i];
                i++;
            }
            i--;
            int times = stoi(_s);
            for(int j = 0; j < times; j++){
                ans += c;
            }
        }
        printf("Case %d: ", ++C);
        cout << ans << endl;
    }
}
