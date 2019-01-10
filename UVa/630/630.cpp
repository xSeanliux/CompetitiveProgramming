#include <iostream>
#include <string.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;



int C, N;
string s;
bool hasPrinted = false;

int main(){
    cin >> C;
    while(C--){
        if(!hasPrinted)
            hasPrinted = true;
        else
            cout << endl;
        cin >> N;
        string sorted;
        map<string, vector<string> > m;
        for(int i = 0 ; i < N; i++){
            cin >> s;
            sorted = s;
            sort(sorted.begin(), sorted.end());
            if(m.count(sorted)){
                m[sorted].push_back(s);
            } else {
                vector <string> v;
                v.push_back(s);
                m.insert(pair<string, vector<string> >(sorted, v));
            }
        }
        while(cin >> s){
            if(s == "END") break;
            sorted = s;
            sort(sorted.begin(), sorted.end());
            cout << "Anagrams for: " << s << endl;
            if(!m.count(sorted)){
                cout << "No anagrams for: " << s << endl;
            } else {
                int L = m[sorted].size();
                for(int i = 0; i < L; i++){
                    printf("%3d) ", i + 1);
                    cout << m[sorted][i] << endl;
                }
            }
        }
    }
}
