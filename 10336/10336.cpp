#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int T, w, h, counter = 1, occ[26];
char arr[100][100];

vector<pair<char, int> > vec;

void dfs(int y, int x, char currentChar){
    if(y >= h || x >= w || x < 0 || y < 0 || arr[y][x] != currentChar){
        return;
    } else {
        arr[y][x] = '.';
        dfs(y + 1, x, currentChar);
        dfs(y - 1, x, currentChar);
        dfs(y, x + 1, currentChar);
        dfs(y, x - 1, currentChar);
    }
}

bool cmp(const pair<char, int> a, const pair<char, int> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    cin >> T;
    while(counter <= T){
        vec.clear();
        memset(occ, 0, sizeof(occ));
        cin >> h >> w;
        for(int i = 0 ; i < h; i++){
            for(int j = 0 ; j < w; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0 ; i < h; i++){
            for(int j = 0 ; j < w; j++){
                if(arr[i][j] != '.'){
                    char c = arr[i][j];
                    occ[c - 'a']++;
                    dfs(i, j, arr[i][j]);
                }
            }
        }
        //output
        for(int i = 0 ; i < 26; i++){
            if(occ[i] > 0){
                vec.push_back(pair<char, int>((char)(i + 'a'), occ[i]));
            }
        }
        cout << "World #" << counter<<endl;
        int l = vec.size();
        sort(vec.begin(), vec.end(), cmp);
        for(int i = 0 ; i < l; i++){
            cout << vec[i].first <<": " <<vec[i].second << endl;
        }
        //end of output
        counter++;
    }
}
