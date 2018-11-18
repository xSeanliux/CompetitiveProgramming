#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

int N, M, a, b, c;
int num[30010]; //ancestors
int temp[30010]; //path
int ans[30010]; //friends number
int d;

int main() {
    while (cin >> a) {
        for (int i = 0; i < a; i++) {
            cin >> N >> M;
            for (int j = 1; j <= N; j++) {
                num[j] = j;
                ans[j] = 1;
            }
            for (int j = 0; j < M; j++) {
                cin >> b >> c;
                int e = 0;
                while (num[b] != b) {
                    temp[e] = b;
                    b = num[b];
                    e++;
                }
                for (int k = 0; k < e; k++) {
                    num[temp[k]] = b;
                }
                e = 0;
                while (num[c] != c) {
                    temp[e] = c;
                    c = num[c];
                    e++;
                }
                for (int k = 0; k < e; k++) {
                    num[temp[k]] = c;
                }
                if (b != c) {
                    num[c] = b;
                    ans[b] += ans[c];
                }
            }
            d = 0;
            for (int r = 1; r <= N; r++) {
                if (ans[r] >= d) {
                    d = ans[r];
                }
            }
            cout << d << endl;
        }
    }
    return 0;
}
