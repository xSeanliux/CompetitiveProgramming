#include <iostream>
#include <algorithm>
#define N 200
using namespace std;

bool is_prefix(string a, string b) {
  for (int i = 0; i < b.length(); i++) {
    if (a[i] != b[i]) return 0;
  }
  return 1;
}

bool is_suffix(string a, string b) {
  for (int i = 1; i <= b.length(); i++) {
    if (a[a.length()-i] != b[b.length()-i]) return 0;
  }
  return 1;
}

int n;
string PS[N+5];
int A = -1, B;
int father[N+5];
int pre[N+5], suf[N+5];
int choose[N+5];

int main() {
  cin >> n;
  for (int i = 0; i < 2*n-2; i++) {
    cin >> PS[i];
    if (PS[i].length() == n-1) {
        if(A < 0) A = i;
        else B = i;
    }
  }
  for (int i = 0; i < 2*n-2; i++) {
    if (is_prefix(PS[A], PS[i])) pre[i]++, pre[A]++;
    if (is_prefix(PS[B], PS[i])) pre[i]++, pre[B]++;
    if (is_suffix(PS[A], PS[i])) suf[i]++, suf[A]++;
    if (is_suffix(PS[B], PS[i])) suf[i]++, suf[B]++;
  }
  if (pre[A] < n) pre[A] = 0;
  if (pre[B] < n) pre[B] = 0;
  if (suf[A] < n) suf[A] = 0;
  if (suf[B] < n) suf[B] = 0;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 2*n-2; i++) {
      if (pre[i] && !suf[i] && !is_prefix(PS[B], PS[i])) suf[A] = 0;
      if (pre[i] && !suf[i] && !is_prefix(PS[A], PS[i])) suf[B] = 0;
      if (suf[i] && !pre[i] && !is_suffix(PS[B], PS[i])) pre[A] = 0;
      if (suf[i] && !pre[i] && !is_suffix(PS[A], PS[i])) pre[B] = 0;
    }
    for (int i = 0; i < 2*n-2; i++) {
      if (pre[i] && !pre[A] && (!is_prefix(PS[B], PS[i]) || !pre[B])) pre[i] = 0;
      if (pre[i] && !pre[B] && (!is_prefix(PS[A], PS[i]) || !pre[A])) pre[i] = 0;
      if (suf[i] && !suf[A] && (!is_suffix(PS[B], PS[i]) || !suf[B])) suf[i] = 0;
      if (suf[i] && !suf[B] && (!is_suffix(PS[A], PS[i]) || !suf[A])) suf[i] = 0;
    }
  }
  for (int i = 0; i < 2*n-2; i++) {
    if (pre[i] && !choose[PS[i].length()]) cout << 'P', choose[PS[i].length()] = 1;
    else cout << 'S';
  }
  cout << endl;
  return 0;
}
