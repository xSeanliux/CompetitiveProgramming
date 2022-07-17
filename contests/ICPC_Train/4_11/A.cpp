#include <iostream>
#include <math.h>
using namespace std;

const int N = 6;
bool mp[10][10], nmp[10][10];

inline void flipH() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N / 2; j++) {
      swap(mp[i][j], mp[i][N - 1 - j]);
    }
  }
}

inline void flipV() {
  for(int i = 0; i < N / 2; i++) {
    for(int j = 0; j < N; j++) {
      swap(mp[N - 1 - i][j], mp[i][j]);
    }
  }
}

inline void rot() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      nmp[j][N - 1 - i] = mp[i][j]; 
    }
  }
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) mp[i][j] = nmp[i][j];
}

bool isValid(int i, int j) {
  return i >= 0 && j >= 0 && i < N && j < N && mp[i][j];
}

bool check() {
  //check for center four
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(isValid(i, j) && isValid(i, j + 1) && isValid(i, j + 2) && isValid(i, j + 3)) {
        if(isValid(i - 1, j) || isValid(i - 1, j + 1) || isValid(i - 1, j + 2) || isValid(i - 1, j + 3)) {
          if(isValid(i + 1, j) || isValid(i + 1, j + 1) || isValid(i + 1, j + 2) || isValid(i + 1, j + 3)) return true;
        }
      }
    }
  }
  //check for 
  for(int i = 1; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(isValid(i, j) && isValid(i, j + 1) && isValid(i, j + 2) && isValid(i + 1, j + 2) && isValid(i + 1, j + 3)) {
        if(isValid(i - 1, j) || isValid(i - 1, j + 1) || isValid(i - 1, j + 2) || isValid(i + 1, j + 4)) return true;
      }
    }
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if(isValid(i, j) && isValid(i, j + 1) && isValid(i + 1, j + 1) && isValid(i + 1, j + 2) && isValid(i + 2, j + 2) && isValid(i + 2, j + 3)) return true;
    }
  }
  return false;
}

int main() {
  for(int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < N; j++) {
      mp[i][j] = (s[j] == '#');
    }
  }
  bool can = false;
  for(int i = 0; i < 5; i++) {
    can |= check();
    flipH();
    can |= check();
    flipH();
    
    flipV();
    can |= check();
    flipV();

    flipH();
    flipV();
    can |= check();
    flipH();
    flipV();

    rot();
  }
  if(can) {
    cout << "can fold\n";
  } else {
    cout << "cannot fold\n";
  }
}