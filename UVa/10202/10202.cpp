#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, sum, t;
vector <int> vec, sols;

int main(){
    while(scanf("%d", &N) != EOF){
        sum = 0;
        vec.clear();
        sols.clear();
        for(int i = 0; i < N*(N-1)/2; i++){
            scanf("%d", &t);
            vec.push_back(t);
            sum += t;
        }
        cout << sum << endl;
        if(sum % (N-1) == 0){
            sum /= (N-1);
            for(int i = 0; i < N; i++){
                sols.push_back(sum - vec[i]);
            }
            sort(sols.begin(), sols.end());
            printf("%d", sols[0]);
            for(int i = 1; i < N; i++)
                printf(" %d", sols[i]);
            printf("\n");
        } else {
            printf("Impossible\n");
        }
    }
}
