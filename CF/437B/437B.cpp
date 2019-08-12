#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int lim, sum;
vector<deque<int> > allvals;
vector<int> ans;
int main(){
    cin >> sum >> lim;
    allvals.resize(20);
    for(int i = 1; i <= lim; i++){
        for(int j = 0; (1 << j) <= i; j++){
            if(i & (1 << j)){
                allvals[j].push_back(i);
                break;
            }
        }
    }
    ans.clear();
    for(int i = 20; i >= 0; i--){
        while(allvals[i].size() && sum >= (1 << i)){
            ans.push_back(allvals[i].front());
            allvals[i].pop_front();
            sum -= (1 << i);
        }
    }
    if(sum > 0){
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for(int i : ans){
            cout << i << " ";
        }
    }
}
