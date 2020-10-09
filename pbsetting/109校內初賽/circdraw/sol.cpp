#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma loop_opt(on)
#include <unistd.h>
using namespace std;

int N;
long long int x, y;
double sx, sy, s2;

constexpr int kBufSize = 16384;

inline char Readchar() {
  static char buf[kBufSize];
  static char *p = buf, *end = buf;
  if (p == end) end = buf + read(0, buf, kBufSize), p = buf;
  return *p++;
}

template <class T> inline void Input(T& a) {
  char p;
  while ((p = Readchar()) < '-');
  if (p == '-') {
    a = 0;
    while ((p = Readchar()) >= '0') a *= 10, a -= p ^ '0';
  } else {
    a = p ^ '0';
    while ((p = Readchar()) >= '0') a *= 10, a += p ^ '0';
  }
}

#include <cstdio>

signed main(){
	Input(N);
	for(int i = 0; i < N; i++){
		Input(x);
		Input(y);
		s2 += x * x + y * y;
		sx += x;
		sy += y;
	}
	printf("%.8lf\n", (3.1415926535) / 2 * (N * s2 - sx * sx - sy * sy));
}
