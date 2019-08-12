#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long int X;
vector<unsigned long long int> vec;
int main(){
    while(cin >> X){
        vec.clear();
        if(!X) return 0;
        for(int i = 0; i < 10; i++){
            if(!((X - i) % 9)){
                vec.push_back(((X - i) / 9) * 10 + i);
            }
        }
        sort(vec.begin(), vec.end());
        printf("%llu", vec[0]);
        for(int i = 1; i < vec.size(); i++) printf(" %llu", vec[i]);
        printf("\n");
    }
}
