#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define pb push_back
using namespace std;
//By S
unsigned long long int ans(vector<int> vec){

    if(vec.size() == 1) return 0;
    vector<int> left, right;
    for(int i = 0; i < vec.size()/2; i++){
        left.pb(vec[i]);
        right.pb(vec[i + vec.size()/2]);
    }
    if(vec.size() % 2) right.pb(vec[vec.size() - 1]);
    int ansl = ans(left);
    int ansr = ans(right);
    sort(left.begin(), left.end()); //crucial to ensure lower_bound works
    //sort(right.begin(), right.end());
    unsigned long long int res = 0;
    /*
    printf("The answer for vec:\n");
    for(int n: vec) {
        printf("%d ", n);
    }
    */
    for(int n : right){
        res += left.size() - (lower_bound(left.begin(), left.end(), n + 1) - left.begin()); //number of elements in left such that element is smaller than n
    }
    //printf("\nis %d\n", res + ansl + ansr);
    res += ansl + ansr;
    return res;
}

int N, k, c = 0;

int main(){
    while(cin >> N){
        if(!N) return 0;
        vector<int> vec;
        for(int i = 0; i < N; i++){
            scanf("%d", &k);
            vec.pb(k);
        }
        printf("Case #%d: %llu \n", ++c, ans(vec));
    }
}


