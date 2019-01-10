
#include <iostream>
#include <map>
using namespace std;


map <string, int> cnt;
int T;
int main(){
    while(cin >> T){
        int ans = 0, arr[5];
        for(int i = 0 ; i < T; i++){
            for(int j = 0; j < 5; j++)
                cin >> arr[j];
            sort(arr, arr + 5);
            string s = "";
            for(int j = 0; j < 5; j++){
                s += to_string(arr[j]) + '|';
            }
            if(cnt.count(s)){
                cnt[s]++;
            } else {
                cnt.insert(pair<string, int>(s, 1));
            }
            if(cnt[s] > ans) ans = cnt[s];
        }
        cout << ans << endl;
    }
}

