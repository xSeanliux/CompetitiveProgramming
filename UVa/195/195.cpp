#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

int N;
string s;


bool cmp(const char a, const char b){
    if(tolower(a) != tolower(b)) return tolower(a) < tolower(b);
    else return a < b;
}

int main(){
    cin >> N;
    while(N--){
        cin >> s;
        sort(s.begin(), s.end(), cmp);
       do{
            cout << s << endl;
       }while(next_permutation(s.begin(), s.end(), cmp));
    }
}
