#include <iostream>
#include <set>
using namespace std;

int N, sum;
set <int> prefs;

int main(){
    while(cin >> N){
        prefs = set <int>();
        int sum = 0, t, ans = 0;
        for(int i = 0 ; i < N; i++){
            cin >> t;
            sum += t;
            prefs.insert(sum);
        }
        if(sum % 3){
            cout << "0" << endl;
            break;
        } else {
            int aLen = sum / 3;
            while(!prefs.empty()){
                int k = prefs.front();
                int bot = (100 * k - aLen) % aLen;
                int top = (k + aLen) % aLen;
                if(prefs.count(bot) && prefs.count(top)){
                    ans++;
                    prefs.erase(bot);
                    prefs.erase(top);
                }
                prefs.erase(k);
            }
            cout << ans << endl;
        }
    }

}
