#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int x, s = 0, sq = 0;
    for(int i = 0; i < N; i++) {
        cin >> x;
        s += x;
        sq += x * x;
    }
    cout << s * s << " " << sq << endl;
}
