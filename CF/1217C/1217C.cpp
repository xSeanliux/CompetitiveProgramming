#include <iostream>
#include <string.h>
#include <deque>
using namespace std;

string s;
deque<int> dq;
int q;
long long int ans = 0;

int main(){
    cin >> q;
    while(q--){
        cin >> s;
        //cout << "LEN = " << s.length() << endl;
        ans = 0;
        int sum, ind;
        dq = deque<int>();
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                dq.push_back(i);
            }
            sum = 0;
            for(int j = dq.size() - 1; j >= 0; j--){
                if(i - dq[j] > 31) break;
                sum += (1LL << (i - dq[j]));
                ind = i - sum + 1;
                if(j){
                    if((ind <= dq[j]) && (ind > dq[j - 1])){
                        ans++;
                        //cout << "From " << ind << " to " << i << endl;
                    }
                } else {
                    if(ind >= 0 && ind <= dq[j]){
                        ans++;
                        //cout << "From " << ind << " to " << i << endl;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}
