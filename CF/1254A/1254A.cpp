#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 100;

int T, r, c, k;
char mp[maxN][maxN], belong[maxN][maxN];

string id = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main(){
    ericxiao;
    cin >> T;
    while(T--){
        cin >> r >> c >> k;
        int rC = 0;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                cin >> mp[i][j];
                rC += (mp[i][j] == 'R');
            }
        int avg = rC / k, ext = rC % k, currentChicken = 0, currentRice = 0;
        for(int i = 0; i < r; i++){
            if(i % 2){
                for(int j = c - 1; j >= 0; j--){
                    if(currentChicken < ext){
                        if(currentRice == avg + 1 && (mp[i][j] == 'R')){
                            currentChicken++;
                            currentRice = 0;
                        }
                    } else {
                        if(currentRice == avg && (mp[i][j] == 'R')){
                            currentChicken++;
                            currentRice = 0;
                        }
                    }
                    belong[i][j] = id[currentChicken];
                    currentRice += (mp[i][j] == 'R');
                }
            } else {
                for(int j = 0; j < c; j++){
                    if(currentChicken < ext){
                        if(currentRice == avg + 1 && (mp[i][j] == 'R')){
                            currentChicken++;
                            currentRice = 0;
                        }
                    } else {
                        if(currentRice == avg && (mp[i][j] == 'R')){
                            currentChicken++;
                            currentRice = 0;
                        }
                    }
                    belong[i][j] = id[currentChicken];
                    currentRice += (mp[i][j] == 'R');
                }
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cout << belong[i][j];
            }
            cout << '\n';
        }
    }
}
