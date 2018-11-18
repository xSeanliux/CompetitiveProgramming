#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct Country{
    string s;
    int w;
};

Country countries[2000 + 5];

string c, s, _t;
int n, head, k;

int countryExists(string s){
    for(int i = 0; i < head; i++){
        if(countries[i].s == s) return i;
    }
    return -1;
}

bool comp(Country a, Country b){
    return(a.s < b.s);
}

int main(){
    for(int i = 0; i < 2005; i++){
        countries[i].s = "";
        countries[i].w = 0;
    }
    cin >> n;
    getline(cin, _t);
    head = 0;
    for(int kk = 0; kk < n; kk++){
        getline(cin, s);
        int l = s.length();
        for(k = 0; k < l; k++){
            if(s[k] == ' ') break;
        }
        c = s.substr(0, k);
        int r = countryExists(c);

        if(r == -1){
            countries[head].s = c;
            countries[head].w = 1;
            head++;
        } else {
            countries[r].w++;
        }
    }
    sort(countries, countries + head, comp);
    for(int i = 0; i < head; i++){
        if(countries[i].w > 0){
            cout << countries[i].s << " " << countries[i].w << endl;
        }
    }

}
