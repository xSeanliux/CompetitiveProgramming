#include <iostream>
#include <string.h>
using namespace std;

string s, _t;
int n, i, j, c = 1;

int main(){
    while(getline(cin, s)){
        if(s == "") return 0;
        cout << "Case " << c << ":" << endl;
        cin >> n;
        int l = s.length();
        for(int z = 0; z < n; z++){
            cin >> i >> j;
            if(i > j) swap(i , j);
            char N = s[i];
            bool flag = true;
            for(int k = i + 1; k <= j; k++){
                if(s[k] != N){
                    flag = false;
                    break;
                }
            }
            if(flag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        c++;
        getline(cin, _t);
    }

}
