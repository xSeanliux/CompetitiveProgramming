#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <map>
#include <set>
#include <iomanip>
#include <numeric>
#include <queue>
#include <algorithm>
#include <stack>
#include <vector>
#include <utility>
using namespace std;
using ll = long long;
using ld = long double;



template<typename T = long long, int p = 1000000007, int base = 101, char h = 'a'>
struct string_hash {
    vector<T> v; //v[i]: hash value
    vector<T> up; //up[i] = b^i mod p
    string_hash(){};
    template<typename S> string_hash(const S &w){
        v.resize(w.size()+1);
        up.resize(w.size()+1);
        up[0] = 1;
        for(int i = 0;i < w.size();++i){
            v[i+1] = (v[i] * base + w[i] - h+1) % p;
            up[i+1] = up[i] * base % p;
        }
    }
    //[l, r], 1-base but string is 0-base lol
    T query(int l, int r){
        return (v[r] + p - v[l-1] * up[r-l+1] % p) % p;
    }
};

vector<string> split(string s) {
  vector<string> v;
  string cs = "";
  for(char c : s) {
    if(c == ' ') {
      if(cs != "") {
        v.push_back(cs);
      }
      cs = "";
    } else cs += c;
  }
  if(cs != "") {
    v.push_back(cs);
  }
  return v;
}



void solve(int seed) {
  int state = (seed << 6) | seed;
  int rnd = 0;
  
  for(int i = 1; i <= 16; i++) {
    int response_bit = (state & 1) ^ ((state >> 4) & 1) ^ ((state >> 10) & 1) ^ ((state >> 11) & 1);
    state = (state >> 1) | (response_bit << 12);
    rnd = (rnd << 1) | response_bit;
  }
  for (int j = 0; j < 41; j++) {

    int rnd = 0;
  
    for(int i = 1; i <= 16; i++) {
      int response_bit = (state & 1) ^ ((state >> 4) & 1) ^ ((state >> 10) & 1) ^ ((state >> 11) & 1);
      state = (state >> 1) | (response_bit << 12);
      rnd = (rnd << 1) | response_bit;
    }
  }
  for (int j = 0; j < 5; j++) {

    int rnd = 0;
  
    for(int i = 1; i <= 16; i++) {
      int response_bit = (state & 1) ^ ((state >> 4) & 1) ^ ((state >> 10) & 1) ^ ((state >> 11) & 1);
      state = (state >> 1) | (response_bit << 12);
      rnd = (rnd << 1) | response_bit;
    }
    cout << rnd << " ";
  }
  cout << "\n";
}


int main() {
  int seed = 0;
  while(cin >> seed) {
    solve(seed);
  }
}