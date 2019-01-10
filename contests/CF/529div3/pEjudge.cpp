#include <iostream>
#include <string.h>
#include <stack>
#include <math.h>
using namespace std;
int N;
string str;

int ownJudge(){
    int nO[N + 2], nC[N + 2];//no. Open, No. Closed
    if(str[0] == ')'){
        nC[0] = 1;
        nO[0] = 0;
    } else {
        nO[0] = 1;
        nC[0] = 0;
    }
    for(int i = 1; i < N; i++){
        nC[i] = nC[i-1];
        nO[i] = nO[i-1];
        if(str[i] == ')'){
            nC[i]++;
        } else {
            nO[i]++;
        }
    }
    if(abs(nO[N-1] - nC[N-1]) != 2){
        return 0;
    }
    int ans1 = 0;
    if(nO[N-1] > nC[N-1]){ //turn ( into ) - O - 1, C + 1
        for(int i = 0; i < N; i++){
            if(nO[i] - 1 < nC[i] + 1){
                ans1 = 0;
            } else if(str[i] == '(' && i != 0) ans1++;
        }
    } else {
        for(int i = 0; i < N; i++){
            if(nO[i] + 1 < nC[i] - 1){
                ans1 = 0;
            } else if(str[i] == ')' && i != N-1) ans1++;
        }
    }
    reverse(str.begin(), str.end());
    if(str[0] == '('){
        nC[0] = 1;
        nO[0] = 0;
    } else {
        nO[0] = 1;
        nC[0] = 0;
    }
    for(int i = 1; i < N; i++){
        nC[i] = nC[i-1];
        nO[i] = nO[i-1];
        if(str[i] == '('){
            nC[i]++;
        } else {
            nO[i]++;
        }
    }
    int ans2 = 0;
    if(nO[N-1] > nC[N-1]){ //turn ( into ) - O - 1, C + 1
        for(int i = 0; i < N; i++){
            if(nO[i] - 1 < nC[i] + 1){
                ans2 = 0;
            } else if(str[i] == ')' && i != 0) ans2++;
        }
    } else {
        for(int i = 0; i < N; i++){
            if(nO[i] + 1 < nC[i] - 1){
                ans2 = 0;
            } else if(str[i] == '(' && i != N-1) ans2++;
        }
    }
    reverse(str.begin(), str.end());
    return min(ans1, ans2);
}

int toJudge(){
    int n, l, r, c, d;
    char tmp;
    bool tf = 0;
    stack <bool> s;
      n = str.length();
      for (int i = 0; i < n; i++) {
        tmp = str[i];
        if (tmp == ')' && i == 0) tf = 1;
        if (tmp == '(' && i == n-1) tf = 1;
        if (tmp == '(') {
          if (s.size() == 1) c = i;
          s.push(1);
        } else if (s.size()) s.pop();
        else {
          if (!l) d = i;
          l++;
        }
      }
      if (tf && ((l == 2 && !s.size()) || (l == 0 && s.size() == 2))) return tf;
      else if (l == 2 && !s.size()) return d/2+1;
      else if (l == 0 && s.size() == 2) return (n-c)/2+1;
      else return 0;

}

string get(int len, int K){
    string ans = "";
    while(K){
        ans = ans + ((K % 2) ? ')' : '(');
        K /= 2;
    }
    while(ans.length() < len) ans = '(' + ans;
    return ans;
}


int main(){
    for(int len = 1; len <= 10; len++){
        N = len;
        for(int k = 0; k < pow(2, len); k++){
            str = get(len, k);
            int a= ownJudge(), b = toJudge();
            if(a != b){
            cout << str << endl;
            cout << a << ", " << b << endl;
            }
        }
    }
}
