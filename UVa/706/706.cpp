#include <iostream>
#include <string.h>
using namespace std;


string gen(char c, int part, int s){
    string res = "";
    int N = c - '0';
    if(part == 1){
        if(N == 1 || N == 4){
            for(int i = 0 ; i < s + 2; i++){
                res += " ";
            }
        } else {
            res = " ";
            for(int i = 0 ; i < s; i++){
                res += "-";
            }
            res += " ";
        }
    } else if(part == 2){
        if(N == 1 || N == 2 || N == 3 || N == 7){
            for(int i = 0 ; i < s + 1; i++){
                res += " ";
            }
            res += "|";
        } else if(N == 5 || N == 6){
            res += "|";
            for(int i = 0 ; i < s + 1; i++){
                res += " ";
            }
        } else {
            res += "|";
            for(int i = 0 ; i < s; i++){
                res += " ";
            }
            res += "|";
        }
    } else if(part == 3){
        if(N == 1 || N == 7 || N == 0){
            for(int i = 0 ; i < s + 2; i++){
                res += " ";
            }
        } else {
            res += " ";
            for(int i = 0 ; i < s; i++){
                res += "-";
            }
            res += " ";
        }
    } else if(part == 4){
        if(N == 1 || N == 7 || N == 4 || N == 3 || N ==  5 || N ==  9){
            for(int i = 0 ; i < s + 1; i++){
                res += " ";
            }
            res += "|";
        } else if(N == 6 || N == 8 || N == 0) {
            res += "|";
            for(int i = 0 ; i < s; i++){
                res += " ";
            }
            res += "|";
        } else {
            res += "|";
            for(int i = 0 ; i < s + 1; i++){
                res += " ";
            }

        }
    } else if(part == 5){
        if(N == 1 || N == 4 || N == 7){
            for(int i = 0 ; i < s + 2; i++){
                res += " ";
            }
        } else {
            res += " ";
            for(int i = 0 ; i < s; i++){
                res += "-";
            }
            res += " ";
        }
    }
    return res;
}

string s;
int n, c = 0;

int main(){
    while(cin >> n >> s){
        if(c){
            cout << endl;
        } else {
            c++;
        }
        if(!n) return 0;
        int l = s.length();
        for(int i = 0 ; i < l; i++){
            if(i) cout << " ";
            cout << gen(s[i], 1, n);
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < l; j++){
                if(j) cout << " ";
                cout << gen(s[j], 2, n);
            }
            cout << endl;
        }
        for(int i = 0 ; i < l; i++){
            if(i) cout << " ";
            cout << gen(s[i], 3, n);
        }
        cout << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < l; j++){
                if(j) cout << " ";
                cout << gen(s[j], 4, n);
            }
            cout << endl;
        }
        for(int i = 0 ; i < l; i++){
            if(i) cout << " ";
            cout << gen(s[i], 5, n);
        }
        cout << endl;
    }
}
