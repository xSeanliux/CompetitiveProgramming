#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 326;

struct BIT{
    int bit[maxN], arr[maxN];
    BIT(){
        fill(bit, bit + maxN, 0);
        fill(arr, arr + maxN, 0);
    }
    void add(int p){
        if(arr[p]) return;
        arr[p] = true;
        for(; p < maxN; p += (p & -p)) arr[p]++;
    }
    inline int sum(int p){
        int r = 0;
        for(; p; p -= (p & -p)) r += arr[p];
        return r;
    }
} bit;

vector<pii> points;
int N, x, y;

int main(){
   	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x >> y;
		points.emplace_back(x, y);
	}
	sort(points.begin(), points.end());
	for(int i = 0; i < N; i++){
		bit = BIT();
		bit.add(points[i].S);
		for(int j = i - 1; j >= 0; j--){
			bit.add(points[j].S);
			if(points[j].F < points[i].F){
				if(points[i].S == points[j].S){

				} else {

				}
			}
		}
	}
}
