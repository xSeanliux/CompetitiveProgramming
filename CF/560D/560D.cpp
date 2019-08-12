#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string a, b;
int l;

string transf(string s){
    int k = s.length(), e = 0;
    while(!(k % 2)){
        k /= 2;
        e++;
    }
    vector<string> vec;
    string cs = "";
    for(int i = 0; i < s.length(); i += k){
        cs = "";
        for(int j = 0; j < k; j++){
            cs += s[i + j];
        }
        vec.push_back(cs);
    }
    vector<string> nvec;
    while(vec.size() > 1){
        nvec.clear();
        for(int i = 0; i < vec.size(); i += 2){
            cs = (vec[i] > vec[i + 1] ? vec[i + 1] + vec[i] : vec[i] + vec[i + 1]);
            nvec.push_back(cs);
        }
        vec.clear();
        for(string s : nvec) vec.push_back(s);
    }
    return vec[0];
}



int main(){
    cin >> a >> b;
    if(transf(a) == transf(b)){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}
