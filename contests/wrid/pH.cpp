#include <iostream>
#include <map>
#include <string.h>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define pii pair<int,int>
#define F first
#define S second
#define ps pair<string,int>
using namespace std;

vector<ps> coms;
vector<char> ans;
map<char, int> freq;
int N, ind;
string s, allowed;

int main(){
    ericxiao;
    cin >> s;
    for(char c : s){
        freq[c]++;
    }
    cin >> N;
    ans.resize(N);
    coms.clear();
    for(int i = 0; i < N; i++){
        cin >> ind >> allowed;
        coms.push_back({ind, allowed});
    }
    sort(coms.begin(), coms.end(), [](ps a, ps b){
        return a.F < b.F;
    });
    for(ps r : coms){
        for(char c : r.S){
            if(freq[c]){
                freq[c]--;
                ans[r.F] = c;
                break;
            }
        }
    }
}
