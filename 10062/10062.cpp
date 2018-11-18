#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string str;

struct Data{
    int num, freq;
};

bool cmp(Data d1, Data d2){
    if(d1.freq > d2.freq){
        return true;
    } else if(d1.freq < d2.freq){
        return false;
    } else {
        if(d1.num < d2.num){
            return true;
        } else {
            return false;
        }
    }
}
int c;
Data freqs[1000];
int main(){
    c = 1;
    while(getline(cin, str)){
        if(c != 1){
            cout << endl;
        } else {
            c++;
        }
        int l = str.length();
        for(int i = 0; i < 1000; i++){
            freqs[i].num = i;
            freqs[i].freq = 0;
        }
        for(int i = 0; i < l ; i++){
            freqs[(int)(str[i])].freq++;
        }
        sort(freqs, freqs+1000, cmp);
        for(int i = 1000; i >= 0; i--){
            if(freqs[i].freq == 0){
            } else {
                printf("%d %d\n", freqs[i].num, freqs[i].freq);
            }
        }

    }
}
