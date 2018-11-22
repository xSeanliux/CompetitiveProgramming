#include <iostream>
#include <string.h>
using namespace std;

unsigned long long int m[100][100], paths[100][100], stuff[100], head, c, h, w;
string s;
bool flag = false;

int main(){
    //for(int i = 1; i <= 100; i++) cout << i << endl;
    cin >> c;
    for(int ka = 0 ; ka <= c; ka++){
        cin >> h >> w;
        for(int i = 0 ; i <= h; i++){
            for(int j = 0 ; j <= w ; j++){
                m[i][j] = 0;
                paths[i][j] = 0;
            }
        }
        getline(cin , s);
        //cout << "S1 = " << s << endl;
        //getline(cin , s);
        paths[1][1] = 1;
        for(int i = 0 ; i < h ; i++){
            getline(cin , s);
            //if(s == "") break;
            //cout << "S = " << s << endl;
            int l = s.length();
            string currentString = "";
            head = 0;
            for(int j = 0 ; j < l ; j++){
                if(j == l-1 || s[j] == ' '){
                    if(j == l-1) currentString += s[j];
                    stuff[head] = stoi(currentString);
                    head++;
                    //cout << "stuff[" << head << "] = " << currentString << endl;
                    currentString = "";

                } else {
                    currentString += s[j];
                }
            }
            for(int j = 1 ; j < head; j++ ){
                m[stuff[0]][stuff[j]] = 1;
                //cout << "obstacle at (" << stuff[0] << ", " << stuff[j] << ")" << endl;
            }
        }
        for(int i = 1 ; i <= h; i++){
            for(int j = 1 ; j <= w ; j++){
                if(i != 1 || j != 1){
                    unsigned long long int ans = 0;
                    if(m[i][j] != 1){
                        if(i > 1){
                            ans += paths[i-1][j];
                        }
                        if(j > 1){
                            ans += paths[i][j-1];
                        }
                    }
                    paths[i][j] = ans;
                    //cout << "paths[" << i << "][" << j << "] = " << paths[i][j] << endl;
                }

            }
        }
        if(flag) cout << endl;
        else flag = true;
        cout << paths[h][w] << endl;
        //printf("%lld\n", paths[h][w]);
    }
}
