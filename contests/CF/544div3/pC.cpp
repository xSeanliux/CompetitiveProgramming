#include <iostream>
#include <map>
using namespace std;

map<int, int> freq;
int N, x;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x;
        if(freq.count(x)) freq[x]++;
        else freq.insert({x, 1});
    }
    int ans = 1, ca = 1;
    for(auto i = freq.begin(); i != freq.end(); i++){
        ca = 0;
        for(auto j = i; j != freq.end() && j->first - i->first <= 5; j++){
            ca += j->second;
        }
        ans = max(ca, ans);
    }
    cout << ans << endl;
}
