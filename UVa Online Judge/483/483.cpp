#include <iostream>
#include <string.h>

using namespace std;

string s, cS;
string words[100000];
int head;

string rev(string s){
    int l = s.length();
    string res = "";
    for(int i = l-1; i >= 0; i--){
        res += s[i];
    }
    return res;
}

int main()
{
    while(getline(cin, s)){
        int l = s.length();
        head = 0;
        cS = "";
        for(int i = 0 ; i < l; i++){
            if(s[i] == ' ' && i != l-1){
               words[head] = cS;
               head++;
               cS = "";
            } else {
                cS += s[i];
                if(i == l-1){
                    words[head] = cS;
                   head++;
                   cS = "";
                }
            }
        }
        for(int i = 0 ; i < head; i++){
            if(i > 0) cout << " ";
            cout << rev(words[i]);
        }
        cout << endl;
    }
}
