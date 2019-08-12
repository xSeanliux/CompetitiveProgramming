#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int d, T, cnt;
string s;

int main(){
    scanf("%d", &T);
    while(T--){
        cnt = 0;
        cin >> s >> d;
        sort(s.begin(), s.end());
        do{
            cnt += !(stoll(s, nullptr) % d);
        }while(next_permutation(s.begin(), s.end()));
        cout << cnt << endl;
    }
}
