#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int N;
string s;
vector<int> e, ne;
int main(){
    cin >> N >> s;
    string newS;
    int rounds = (N - 11)/2;
    char c;
    for(int i = 0; i < s.length(); i++){
        c = s[i];
        (c == '8' ? e : ne).push_back(i);
    }
    if(e.size() <= rounds){
        cout << "NO" << endl;
        return 0;
    }
    if(e[rounds] - rounds <= rounds){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
