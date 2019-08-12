#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;

int n, m, h, x;
vector<int> hs;
int heights[100][100];
string s;


int main(){
    cin >> n >> m >> h;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            heights[i][j] = 1e5;
        }
    }
    for(int i = 0; i < m; i++){
        cin >> x;
        for(int j = 0; j < n; j++){
            heights[j][i] = min(heights[j][i], x);
        }
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        for(int j = 0; j < m; j++){
            heights[i][j] = min(heights[i][j], x);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> x;
            if(!x) heights[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << heights[i][j] << " ";
        }
        cout << endl;
    }
}

