#include <iostream>
#include <math.h>
#include <vector>
#include <deque>
#define int long long int
using namespace std;

int T, N, k, a;
deque<int> current;


signed main(){
    cin >> T;
    while(T--){
        cin >> N >> k;
        int minAns = 1e10, ind = 0;
        current = deque<int>();
        while(N--){
            cin >> a;
            current.push_back(a);
            while(current.size() > k + 1) current.pop_front();
            if(current.size() == k + 1){
                int x = (current.front() + current.back()) / 2;
                int d = max(abs(x - current.front()), abs(x - current.back()));
                //cout << "d = " << d << endl;
                //cout << minAns << endl;
                if(d < minAns){
                    minAns = d;
                    ind = x;
                    //cout << "new ind = " << ind << endl;
                }
            }
        }
        cout << ind << endl;
    }
}
