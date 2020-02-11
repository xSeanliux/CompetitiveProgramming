#include <iostream>
#include <vector>
#include <utility>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int N, x, y;

struct Point{
	int id, x, y;
	Point(){}
	Point(int id, int x, int y): id(id), x(x), y(y){}
};

vector<Point> pts, A[2][2];

int main(){
	ericxiao;
	cin >> N;
	bool can = false;
	for(int i = 1; i <= N; i++){
		cin >> x >> y;
		pts.emplace_back(i, x + 1e6, y + 1e6);
	}
	while(!can){
		for(Point pt : pts){
			A[pt.x % 2][pt.y % 2].push_back(pt);
		}
		for(int i = 0; i < 2; i++){
			for(int j = 0; j < 2; j++){
				if(A[i][j].size() && A[i][j].size() < N){
					can = true;
					break;
					
				}
			}
		}
		if(!can){
			pts.clear();
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					for(Point &p : A[i][j]){
						p.x /= 2;
						p.y /= 2;
						pts.push_back(p);
					}
					A[i][j].clear();
				}
			}
		}
	}
	if(A[0][0].size() + A[1][1].size() == 0 || A[0][0].size() + A[1][1].size() == N){
		if(A[0][0].size()){
  			cout << A[0][0].size() << endl;
			for(Point p : A[0][0]){
				cout << p.id << " ";
			}
			cout << endl;
			return 0;
		} else {
			cout << A[0][1].size() << endl;
			for(Point p : A[0][1]){
				cout << p.id << " ";
			}
			cout << endl;
			return 0;
		}
	}
	cout << A[0][0].size() + A[1][1].size() << endl;
	for(Point p : A[0][0]){
		cout << p.id << " ";
	}
	for(Point p : A[1][1]){
		cout << p.id << " ";
	}
	cout << endl;


}


