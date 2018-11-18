#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;


string currentStr;
int m, c, head, maxi;

struct Url{
    string url;
    int freq = 0;
};
Url urls[15];
int alreadyUrl(string s){
    for(int i = 0; i < 10; i++){
        if(urls[i].url == s){
            return i;
        }
    }
    return -1;
}

bool comp(Url a, Url b){
    //cout << "starting" << a.url << ", " << b.url << endl;
    string aprime = a.url.substr(4);
    string bprime = b.url.substr(4);
    //cout << "a': " << aprime << ", b': " << bprime << endl;
    if(aprime <= bprime){
        return true;
    } else {
        return false;
    }
}

int main(){
    cin >> c;
    for(int as = 1; as <= c; as++){
        head = 0;
        maxi = 0;
        for(int i = 0; i < 10; i++){
                urls[i].url = "";
                urls[i].freq = 0;
            }
        for(int i = 0; i < 10; i++){
            cin >> currentStr >> m;
            int r = alreadyUrl(currentStr);

            if(r == -1){
                //cout << "New url" << endl;
                urls[head].url = currentStr;
                urls[head].freq = m;
                head++;
            } else {
                //cout << "Old url" << endl;
                urls[r].freq = m;

            }

        }
        int _m = 0;
        for(int i = 0; i < 10; i++){
            if(urls[i].freq > _m){
                _m = urls[i].freq;
            }
        }

        sort(urls, urls + head, comp);


        cout << "Case #" << as << ": " << endl;
        for(int i = 0; i < head; i++){
            if(urls[i].freq == _m){
                cout << urls[i].url;
                if(i != head-1 || c != as){
                    cout << endl;
                }
            }
        }

    }
}
