#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

string s;

int getDist(string s){
    int l = s.length();
    //s += s[0];
    int ans = 30;
    for(int i = 0 ; i < l-1; i++){
        ans = min(ans, abs(s[i] - s[i+1]) );
    }
    return ans;
}


int main(){
    while(cin >> s){
        string next = s, prev = s;
        vector <string> vec;
        vec.push_back(s);
        for(int i = 0 ; i < 10; i++){
            next_permutation(next.begin(), next.end());
            prev_permutation(prev.begin(), prev.end());
            vec.push_back(next);
            vec.push_back(prev);
            //cout << next << endl << prev << endl;
        }
        sort(vec.begin(), vec.end());
        int maxDist = 0, maxIndex = 0;
        for(int i = 0 ; i < 10; i++){
            next_permutation(next.begin(), next.end());
            prev_permutation(prev.begin(), prev.end());
            vec.push_back(next);
            vec.push_back(prev);
            //cout << next << endl << prev << endl;
        }
        for(int i = 0; i < 21; i++){
            //cout << vec[i] << ": " << getDist(vec[i]) << endl;
            if(getDist(vec[i]) > maxDist){
                maxIndex = i;
                maxDist = getDist(vec[i]);
            }
        }
        cout << vec[maxIndex] << getDist(vec[maxIndex]) << endl;
    }
}

