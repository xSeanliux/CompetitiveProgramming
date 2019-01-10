#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

struct Obj{
    string s;
    int ind;
};
Obj arr[205], sorted[205];

bool objSort(const Obj a, const Obj b){
    return a.s.length() > b.s.length(); //longest first
}

string s, ansStr;
int N;
bool ans[200];


int main(){
    cin >> N;
    bool flag;
    for(int i = 0 ; i < 2*(N-1); i++){
        cin >> arr[i].s;
        arr[i].ind = sorted[i].ind = i;
        sorted[i].s = arr[i].s;
    }
    sort(sorted, sorted + 2*(N-1), objSort);
    flag = true;
    ansStr = sorted[0].s + sorted[1].s[(N-2)];
    //cout << "ans: " << ansStr << endl;
    ans[sorted[0].ind] = 1; //pre first
    ans[sorted[1].ind] = 0; //suf second
    for(int i = 2; i < 2*(N-1); i+=2){
        string s1 = sorted[i].s;
        string s2 = sorted[i+1].s;
        //cout << "looking at " << s1 << " and " << s2 << endl;
        int l = s1.length();
        //try PS
        if(ansStr.substr(0, l) == s1 && ansStr.substr(ansStr.length() - l) == s2){
            //try PS
            ans[sorted[i].ind] = 1;
            ans[sorted[i+1].ind] = 0;
        } else if(ansStr.substr(0, l) == s2 && ansStr.substr(ansStr.length() - l) == s1){
            //then try SP
            ans[sorted[i].ind] = 0;
            ans[sorted[i+1].ind] = 1;
        } else {
            flag = false;
            //cout << "nope" << endl;
            break;
        }
    }
    if(!flag){
        flag = true;
        ansStr = sorted[1].s + sorted[0].s[(N-2)];
        //cout << "ans: " << ansStr << endl;
        ans[sorted[1].ind] = 1; //pre second
        ans[sorted[0].ind] = 0; //suf first
        for(int i = 2; i < 2*(N-1); i+=2){
            string s1 = sorted[i].s;
            string s2 = sorted[i+1].s;
            //cout << "looking at " << s1 << " and " << s2 << endl;
            int l = s1.length();
            //try PS
            if(ansStr.substr(0, l) == s1 && ansStr.substr(ansStr.length() - l) == s2){
                //try PS
                ans[sorted[i].ind] = 1;
                ans[sorted[i+1].ind] = 0;
            } else if(ansStr.substr(0, l) == s2 && ansStr.substr(ansStr.length() - l) == s1){
                //then try SP
                ans[sorted[i].ind] = 0;
                ans[sorted[i+1].ind] = 1;
            } else {
                flag = false;
                break;
            }
        }
    }
    for(int i = 0; i < 2*(N-1); i++){
        cout << ( (ans[i]) ? 'P' : 'S' );
    }
    cout << endl;
}
