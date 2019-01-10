#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct Ans{
    int ind, ans;
    bool operator()(const Ans a, const Ans b){
        return a.ans > b.ans;
    }
};

priority_queue<Ans> mod0, mod1, mod2;
string s;

int main(){
    cin >> s;
    int currentS = 0;
}
