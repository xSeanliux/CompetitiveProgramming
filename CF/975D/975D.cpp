#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;
int N, a, b, x, vx, vy, ans;
map<int, map<int, int> > mp;
map<int, int> mp2;

struct Jizz{
	int x, vx, vy;
	Jizz(int x, int vx, int vy): x(x), vx(vx), vy(vy){}
	bool operator<(const Jizz &j) const {
		return x < j.x;
	}
};

vector<Jizz> vec;




signed main(){
	cin >> N >> a >> b;	
	for(int i = 0; i < N; i++){
		cin >> x >> vx >> vy;
		vec.emplace_back(x, vx, vy);
	}
	sort(vec.begin(), vec.end());
	for(auto p : vec){
		int key = a * p.vx - p.vy;
		if(!mp.count(key)) mp[key] = map<int,int>();
		ans += mp2[key] - mp[key][p.vx];
		mp[key][p.vx]++;
		mp2[key]++;
	}
	cout << ans * 2 << endl;
}
