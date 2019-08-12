#include<iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

int T, N, t;
bool c = false;
vector<int> vec;
vector<string> arr;
string x, s;

int main(){
    cin >> T;

    while(T--){
        getline(cin, s);
        getline(cin, s);
        getline(cin, s);
        stringstream ss;
        //cout <<"s = " << s << endl;
        ss.str(s);
        vec.clear();
        arr.clear();
        while(ss >> t){
            vec.push_back(t - 1);
            //cout << t-1 << endl;
        }
        //cout << endl;
        arr.resize(vec.size());
        for(int i = 0; i < vec.size(); i++){
            cin >> x;
            arr[vec[i]] = x;
        }

        if(!c) c = true;
        else cout << endl;

        for(string i : arr){
            cout << i << endl;
        }

    }
}
