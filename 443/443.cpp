#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

int N;
vector <long long int> humbles;
set <long long int> reps;

bool cmp(const long long int a, const long long int b){
    return a < b;
}

void getHumble(){
    priority_queue <long long int, vector<long long> , greater<long long> > que;
    que.push(1);
    reps.insert(1);
    while(humbles.size() < 5842){
        long long int top = que.top();
        //printf("%lld is humble\n", top);
        humbles.push_back(top);
        que.pop();
        if(!reps.count(top * 2)){
            que.push(top * 2);
            reps.insert(top * 2);
        }
        if(!reps.count(top * 3)){
            que.push(top * 3);
            reps.insert(top * 3);
        }
        if(!reps.count(top * 5)){
            que.push(top * 5);
            reps.insert(top * 5);
        }
        if(!reps.count(top * 7)){
            que.push(top * 7);
            reps.insert(top * 7);
        }
    }
}

int main(){
    getHumble();
    while(cin >> N){
        if(!N)
            return 0;
        //printf("The %dth humble number is %lld.\n", N, humbles[N-1]);

        if(N % 10 == 1 && N % 100 != 11){
            printf("The %dst humble number is %lld.\n", N, humbles[N-1]);
        } else if(N % 10 == 2 && N % 100 != 12){
            printf("The %dnd humble number is %lld.\n", N, humbles[N-1]);
        } else if(N % 10 == 3 && N % 100 != 13){
            printf("The %drd humble number is %lld.\n", N, humbles[N-1]);
        } else {
            printf("The %dth humble number is %lld.\n", N, humbles[N-1]);
        }

    }
}
