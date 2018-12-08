#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string s;
int k;

int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> s;
        int l = s.length();
        sort(s.begin(), s.end());
        do{
            cout << s << endl;
        } while(next_permutation(s.begin(), s.end()));
        cout << endl;
    }
}
