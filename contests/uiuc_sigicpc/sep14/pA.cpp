#include <iostream>
#include <deque>
using namespace std;

const int maxN = 500;
int N, K, x;
deque<int> dq;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> x;
        dq.push_back(x);
    }
    while(dq.size() && dq.front() <= K) dq.pop_front();
    while(dq.size() && dq.back() <= K) dq.pop_back();
    cout << N - dq.size() << endl;
}
