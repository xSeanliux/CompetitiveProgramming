#include <iostream>
#include <queue>
#include <vector>
using namespace std;


priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
long long int N, x;

int main(){
    while(cin >> N){
        if(!N) return 0;
        while(N--){
            cin >> x;
            pq.push(x);
        }
        long long int cost = 0, a, b;
        while(pq.size() > 1){
            a = pq.top(); pq.pop(); b = pq.top(); pq.pop();
            cost += a + b;
            pq.push(a + b);
        }
        pq.pop();
        cout << cost << endl;
    }
}

