#include <iostream>
#include <queue>
#include <stdlib.h>
#include <set>
#include <string.h>
using namespace std;


string current, okver;

class Word{
public:
    string word;
    bool operator() (const Word &a, const Word &b) const{
        return a.word < b.word;
    }
};


int main(){
    set<Word, Word> dict;
    while(cin >> current){
        int l = current.length();
        okver = "";
        for(int i = 0; i < l; i++){
            if('a' <= current[i] && current[i] <= 'z'){
                okver += current[i];
            } else if('A' <= current[i] && current[i] <= 'Z'){
                okver += (char)(current[i] -= ('A' - 'a'));
            } else {
                if(okver.length()){
                    Word w;
                    w.word = okver;
                    if(!dict.count(w)){
                        dict.insert(w);
                    }
                    //cout << "HEY: " << okver << endl;
                    okver = "";
                    continue;
                }

            }
        }
        if(okver.length()){
            Word w;
            w.word = okver;
            if(!dict.count(w)){
                dict.insert(w);
            }
        }
    }
    for(set<Word>::iterator i  = dict.begin(); i != dict.end(); i++){
        cout << i->word << endl;
    }
}
