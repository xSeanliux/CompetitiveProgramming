#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int N, x, y, C = 0;
string s;

struct Point{
    int x, y;
};

Point arr[16 + 1];
int match[16 + 1];

double dist(const int a, const int b){
    return sqrt((arr[a].x - arr[b].x)*(arr[a].x - arr[b].x) + (arr[a].y - arr[b].y)*(arr[a].y - arr[b].y) );
}



int main(){
    while(cin >> N){
        if(!N) return 0;
        for(int i = 0; i < 2*N; i++){
            cin >> s >> arr[i].x >> arr[i].y;
            if(i % 2) match[i] = i - 1;
            else match[i] = i + 1;
        }
        int upds = 0;
        do{
            for(int j = 0; j < 2*N; j++){
                for(int k = 0; k < 2*N; k++){
                    if(j != match[k] && k != match[j] && dist(j, match[k]) + dist(k, match[j]) < dist(j, match[j]) + dist(k, match[k])){
                        swap(match[k], match[j]);
                    }
                }
            }
        } while(upds);
        double ans = 0;
        for(int i = 0; i < 2*N; i++){
            //printf("(%d, %d) to (%d, %d): %f\n",arr[i].x, arr[i].y, arr[match[i]].x, arr[match[i]].y, dist(i, match[i]));
            ans += dist(i, match[i]);
        }
        printf("Case %d: %.2f\n", ++C, ans/2);
    }
}
