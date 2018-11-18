#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string query, x;
int cases;

struct Letter{
    char c;
    int freq;

};

Letter freq[26];

bool cmp(Letter a, Letter b){
    if(a.freq > b.freq){
        return true;
    } else if(a.freq < b.freq){
        return false;
    } else{
        if(a.c < b.c){
            return true;
        } else if(a.c > b.c){
            return false;
        }
    }

}

int main(){
    for(int i = 0; i < 26; i++){
        freq[i].c = i + 'A';
        freq[i].freq = 0;
    }
    cin >> cases;
    getline(cin, x);


    for(int i = 0; i < cases; i++){
        getline(cin, query);
        int l = query.length();
        for(int i = 0; i < l; i++){
            char c = query[i];
            if(('a' <= c && c <= 'z')){

                freq[c - 'a'].freq++;
            } else if(('A' <= c && c <= 'Z')){
                freq[c - 'A'].freq++;
            }
        }


    }
    sort(freq, freq + 26, cmp);
    for(int i = 0 ; i < 26; i++){
        if(freq[i].freq == 0){
            return 0;
        } else {
            printf("%c %d\n", freq[i].c, freq[i].freq);
        }
    }

}
