#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;


int C, N;
string s;
vector <int> vec;

int main(){
    cin >> C;
    while(C--){
        cin >> N;
        vec.clear();
        string cS = "";
        int l = s.length(), t;
        for(int i = 0 ; i < N; i++){
            cin >> t;
            vec.push_back(t);
        }
        sort(vec.begin(), vec.end());
        int k, ans = 0;
        if(vec.size() % 2){
            k = vec[(vec.size() - 1) / 2];
        } else {
            k = vec[vec.size() / 2];
        }
        for(int i = 0 ; i < vec.size(); i++){
            ans += abs(k - vec[i]);
        }
        cout << ans << endl;

    }
}
