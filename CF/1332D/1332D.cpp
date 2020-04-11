#include <iostream>
using namespace std;

const int INF = 131072;

int k;

int main(){
    scanf("%d\n", &k);
    printf("%d %d\n", 3, 3);
    printf("%d %d %d\n", INF + k, k, k);
	printf("%d %d %d\n", INF, INF, INF + k);
	printf("%d %d %d\n", INF, INF, k);
}
