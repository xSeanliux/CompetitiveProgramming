#include <iostream>
#include <algorithm>
using namespace std;


struct Job{
    long long int B, J;
};

bool jobCmp(const Job a, const Job b){
    return a.B + max(a.J, b.B + b.J) < b.B + max(b.J, a.B + a.J);
}

int N, c = 0;

int main(){
    while(cin >> N){
        if(!N) return 0;
        Job jobs[N + 1];
        for(int i = 0; i < N; i++){
            scanf("%lld %lld", &jobs[i].B, &jobs[i].J);
        }
        sort(jobs, jobs + N, jobCmp);
        long long int currentBriefTime = 0, maxTime = 0;
        for(int i = 0 ; i < N; i++){
            currentBriefTime += jobs[i].B;
            maxTime = max(maxTime, currentBriefTime + jobs[i].J);
        }
        printf("Case %d: %lld\n", ++c, maxTime);
    }
}
