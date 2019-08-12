#include <iostream>
#include <algorithm>
#include <vector>
#define int long long int
using namespace std;

struct Person{
    int a, b;
    Person(){}
    Person(int a, int b): a(a), b(b){}
};

int N, a ,b;
Person p[(int)1e5 + 10];

signed main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> a >> b;
        p[i] = Person(a, b);
    }
    sort(p + 1, p + 1 + N, [](Person i, Person j){
        return i.b + j.a < i.a + j.b;
    });
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans += p[i].a * (i - 1) + p[i].b * (N - i);
    }
    cout << ans << endl;

}
