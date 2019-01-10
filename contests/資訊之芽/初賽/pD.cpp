#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int T;
string s[17], name;
bool hasChosen[17];
vector <string> vec;

bool isNumeric(char c){
    return (c <= '9' && c >= '0');
}

bool isGood(string a, string b, string c){
    if(a == b && b == c){
      //cout << "All equal. stack size:" << sta.size()<< endl;
      return true;
    }
    else if(!isNumeric(a[0]) || !isNumeric(b[0]) || !isNumeric(c[0])){
        return false;
    } else {
        if((a[0] - b[0]) == 1 && (b[0] - c[0]) == 1){
            return true;
        } else {
            return false;
        }
    }
}

void checkStuff(){
    int l = vec.size();
    if(l < 3) return;
    for(int i = 0 ; i < l; i++){
        for(int j = i + 1; j < l; j++){
            for(int k = j + 1; k < l; k++){
                if(isGood(vec[i], vec[j], vec[k])){
                    printf("i = %d, j = %d, k = %d, sizeof vec: %d\n", i, j, k, vec.size());
                    cout << *(vec.begin() + i) << ", " << *(vec.begin() + k) << endl;
                    vec.erase((vec.begin() + i));
                    vec.erase((vec.begin() + j));
                    for(int m = 0 ; m < vec.size(); m++){
                        cout << vec[m] << " ";
                    }
                    cout << endl;
                    vec.erase((vec.begin() + k));
                    cout << "finished" << endl;
                    return;
                }
            }
        }
    }
}

int main(){
    cin >> T;
    while(T--){
        cin >> name;
        for(int i = 0 ; i < 17; i++)
            cin >> s[i];
        sort(s, s + 17);
        bool isGood = false;
        for(int i = 0; i < 17 && !isGood; i++){
            for(int j = i + 1; j < 17 && !isGood; j++){
                if(s[i] == s[j]){
                    vec.clear();
                    memset(hasChosen, false, 17);
                    hasChosen[i] = hasChosen[j] = true;
                    for(int k = 0 ; k < 17; k++){
                        if(!hasChosen[k]){
                            cout << "Pushing: " << s[k] << endl;
                            vec.push_back(s[k]);
                            checkStuff();
                        }
                    }
                    if(vec.empty()){
                        isGood = true;
                    }
                }
            }
        }
        if(isGood){
            cout << name << " can yell out Mahjong!" << endl;
        } else {
            cout << "Nothing happened." << endl;
        }
    }
}

