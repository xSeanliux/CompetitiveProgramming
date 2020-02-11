#include <iostream>
#include <algorithm>
using namespace std;


string p, h;

int t;

int main(){
    cin >> t;
    while(t--){
        cin >> p >> h;
        if(p.length() > h.length()){
            cout << "NO" << endl;
            continue;
        }
        string _s;
        bool can = false;
        sort(p.begin(), p.end());
        for(int i = 0; i <= h.length() - p.length(); i++){
            _s = h.substr(i, p.length());
            //cout << "_s = " << _s << endl;
            sort(_s.begin(), _s.end());
            if(_s == p){
                cout << "YES" << endl;
                can = true;
                break;
            }
        }
        if(!can){
            cout << "NO" << endl;
        }
    }
}
