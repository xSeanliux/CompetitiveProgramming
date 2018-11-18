#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#define INF 3000
using namespace std;

int C, minDist[205][205];
vector <string> words;
map <string , int> ind;
string str, a, b;
bool flag = false;

bool diff(string a, string b){
    int diffs = 0;
    int l = a.length();
    for(int i = 0 ; i < l; i++){
        diffs += (a[i] != b[i]);
    }
    if(diffs == 1)
        return true;
    return false;
}

int main(){
    cin >> C;
    while(C--){
        ind = map<string, int>();
        words.clear();
        while(cin >> str && str != "*"){
            //if(str == "*")
            //  break;
            ind.insert(pair<string, int>(str, words.size()));
            words.push_back(str);
        }
        //cout << "end of dic input" << endl;
        int nWords = words.size();
        for(int i = 0 ; i < nWords; i++){
            for(int j = 0; j < nWords; j++){
                if(i == j){
                    minDist[i][j] = 0;
                } else if(diff(words[i], words[j])){
                    minDist[i][j] = 1;
                } else {
                    minDist[i][j] = INF;
                }
            }
        }
        //run Floyd-Warshall
        for(int k = 0 ; k < nWords; k++){
            for(int i = 0 ; i < nWords; i++){
                for(int j = 0 ; j < nWords; j++){
                    minDist[i][j] = min(minDist[i][k] + minDist[k][j], minDist[i][j]);
                }
            }
        }
        if(!flag)
            flag = true;
        else
            cout << endl;
        getline(cin, str);
        while(getline(cin, str)){
            if(str == "")
                break;
            int delim, l = str.length();
            for(delim = 0 ; delim < l; delim++)
                if(str[delim] == ' ') break;
            string str1 = str.substr(0, delim);
            string str2 = str.substr(delim + 1);
            //cout << "str1: \"" << str1 << "\", str2 = \"" << str2 << "\"" << endl;
            cout << str1 << " " << str2 << " " << minDist[ ind[str1] ][ ind[str2] ] << endl;
        }
    }

}
