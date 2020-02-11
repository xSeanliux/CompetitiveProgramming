#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int maxN = 200;

int N;
bool ans[maxN];
string s;

vector<int> zero, one;

int main(){
    cin >> N >> s;
    zero.push_back(0);
    for(int i = 1; i < N; i++){
        if(!one.size()){
            if(s[i] < s[*zero.rbegin()]){
                one.push_back(i);
            } else {
                zero.push_back(i);
            }
            continue;
        }
        if(s[i] >= s[*zero.rbegin()] && s[i] >= s[*one.rbegin()]){
            (s[*zero.rbegin()] >= s[*one.rbegin()] ? zero : one).push_back(i);
        } else if(s[i] >= s[*zero.rbegin()]){
            zero.push_back(i);
        } else if(s[i] >= s[*one.rbegin()]){
            one.push_back(i);
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int x : one) ans[x] = 1;
    cout << "YES" << endl;
    for(int i = 0; i < N; i++) cout << ans[i];
}
