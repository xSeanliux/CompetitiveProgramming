#include <iostream>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;

const int maxN = 1e5 + 10;

int arr[maxN], pre[maxN], N, res, mv, ord[maxN];

struct Line{
	int m, k; //y = mx + k
	Line(int m, int k): m(m), k(k){}
	inline int eval(int x){
		return m * x + k;
	}
	inline double intersect(Line &l){
		return (k - l.k) * 1.0 / (l.m - m);
	}
};

inline bool covers(Line l1, Line l2, Line l3){ //returns whether l2 is covered by l1 and l3
	//(l1 & l2) >= (l2 & l3)	
	return l1.intersect(l2) >= l2.intersect(l3);
}

deque<Line> lines;

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
		res += i * arr[i];
	}
	for(int i = 1; i <= N; i++){
		//currentline: y = i * x + pre[i].
		Line l = Line(i, pre[i]);
		while(lines.size() >= 2 && covers(lines[lines.size() - 2], lines[lines.size() - 1], l)){
			lines.pop_back(); 
			cout << "POPPING" << endl;
		}
		lines.push_back(l);
		cout << "Inserting y = " << i << "x + " << pre[i] << endl;
	}
	iota(ord, ord + N + 1, 0);
	sort(ord + 1, ord + N + 1, [](int a, int b){
		return arr[a] < arr[b];	
	});
	for(int i = 1; i <= N; i++){
		while(lines.size() > 1 && lines.front().intersect(lines[1]) <= arr[ord[i]]) lines.pop_front();
		cout << "Evaluating: " << arr[ord[i]] << ", line: y = " << lines.front().m << "x + " << lines.front().k << endl; 
		cout << "i = " << ord[i] << ", val = " << arr[ord[i]] << endl;
		mv = max(mv, lines.front().eval(arr[ord[i]]) - ord[i] * arr[ord[i]] - pre[ord[i]]);
	}
	cout << res + mv << endl;
}
