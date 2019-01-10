#include <iostream>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

int N;

int main(){
    while(cin >> N){
        if(!N) return 0;
        set <string> s;
        string cs, ns;
        int l = 0;
        cs = to_string(N);
        cout << "Original number was " << N << endl;
        while(!s.count(cs)){
            s.insert(cs);
            sort(cs.begin(), cs.end());
            ns = cs;
            reverse(ns.begin(), ns.end());
            while(cs.length() > 1 && cs[0] == '0') cs = cs.substr(1);
            N = stoi(ns) - stoi(cs);
            cout << ns << " - " << cs << " = " << N << endl;
            cs = to_string(N);
            l++;
        }
        cout << "Chain length " << l << endl << endl;
    }
}


