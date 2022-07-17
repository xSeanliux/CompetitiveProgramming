#include <iostream>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;
int N, a[maxN], b[maxN];

inline char readchar() {
    static const size_t bufsize = 65536;
    static char buf[bufsize];
    static char *p = buf, *end = buf;
    if (p == end) end = buf + fread_unlocked(buf, 1, bufsize, stdin), p = buf;
    return *p++;
}

inline void const Read(int & p) {
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while (c < '0' || c > '9') {
		c = readchar();
	}
	while (c >= '0' && c <= '9')
		p = (p<<3)+(p<<1)+(c^48), c = readchar();
	p = tmp?-p:p;
}

signed main(){
	Read(N);
	for(int i = 0; i < N; i++) Read(a[i]);
	for(int i = 0; i < N - 1; i++) Read(b[i]);
	sort(a, a + N);
	sort(b, b + N - 1);
	for(int i = 1; i < N; i++) a[i] += a[i - 1];
	int ans = 0;
	for(int i = 0; i < N - 1; i++){
		ans += a[i] * b[N - 2 - i];
	}
	cout << ans << '\n';
}

