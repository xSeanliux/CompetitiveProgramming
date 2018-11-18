#include <iostream>
#include <algorithm>
using namespace std;

int c, N;
int people[1000 + 5];
int main(){
    cin >> c;
    for(int ia = 0; ia < c; ia++){
        cin >> N;
        int s = 0;
        for(int i = 0; i < N; i++){
            cin >> people[i];
            s += people[i];
        }
        double avg = (s+0.0)/N;
        sort(people, people+N);
        int j;
        for(j = 0; j < N; j++){
            if(people[j] > avg) break;
        }
        int people = N - j;
        double percentage = (double)(people)/N * 100;
        printf("%.3f%\n", percentage);
    }

}
