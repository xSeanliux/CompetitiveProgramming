#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int T, x, n;
string _s;
bool f = false;
char l[4] = {'A', 'C', 'G', 'T'};
struct Obj{
  string s;
  int val, ind, freqs[4]; //0A1C2G3T
  void getVal(){
    this->val = 0;
    for(int i = 0; i < 4; i++) freqs[i] = 0;
    for(int i = 0; i < this->s.length(); i++){
      for(int j = 3; j; j--){
        if(s[i] < l[j]) this->val += this->freqs[j];
        else {
          this->freqs[j]++;
          break;
        }
      }
    }
  }
  Obj(){}
  Obj(int ind, string s): ind(ind), s(s){
    getVal();
  }
};

bool cmp(const Obj a, const Obj b){
    return (a.val == b.val ? a.ind < b.ind : a.val < b.val);
}

int main(){
  cin>>T;
  while(T--){
    cin >> x >> n;
    Obj arr[n + 1];
    for(int i = 0; i < n; i++){
        cin >> _s;
        arr[i] = Obj(i, _s);
    }
    sort(arr, arr + n, cmp);
    if(!f) f = true;
    else cout << endl;
    for(int i = 0; i < n - 1; i++){
        cout << arr[i].s << endl;
    }
    cout << arr[n-1].s << endl;
    //if(T > 1) cout << endl;
    //cout << endl;
  }
}
