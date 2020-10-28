#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 326;
int N;
int cards[maxN], newcards[maxN], pos[maxN];
vector<vector<int>> ans, jizz;

inline bool done(){
	for(int i = 1; i <= N; i++) if(i != cards[i]) return false;
	return true;
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> cards[i];
	}
	while(!done()){
		for(int i = 1; i <= N; i++) pos[cards[i]] = i;	
		vector<int> v, x;
		v.clear();
		x.clear();
		for(int i = 1; i < N; i++){
			if(pos[i] > pos[i + 1]){
				if(pos[i + 1] > 1) v.push_back(pos[i + 1] - 1);
				bool f = false;
				for(int j = pos[i + 1] + 1; j < pos[i]; j++){
					if(cards[j - 1] + 1 != cards[j]){
						v.push_back(j - pos[i + 1]);	
						v.push_back(pos[i] - j + 1);
						f = true;
						break;
					}
				}
				if(!f){
					v.push_back(pos[i] - pos[i + 1]);
					v.push_back(1);
				}
				if(pos[i] != N) v.push_back(N - pos[i]);
				break;
			}
		}
		//cout << "do: " << endl;
		//for(int x : v) cout << x << " ";
		//cout << endl;

		vector<vector<int>>().swap(jizz);
		int cnt = 0;
		for(int i = 1; i <= N; i++){
			x.push_back(cards[i]);	
			if(x.size() == v[cnt]){
				jizz.push_back(x);
				x.clear();
				cnt++;
			}
		}
		reverse(jizz.begin(), jizz.end());
		int i = 1;
		for(auto v : jizz)
			for(int t : v){
				cards[i++] = t;
			}
		//cout << "cards: " << endl;
		//for(int i = 1; i <= N; i++) cout << cards[i] << " ";
		//cout << endl;
		ans.push_back(v);
	}
	cout << ans.size() << endl;
	for(auto v : ans){
		cout << v.size() << " ";
		for(int x : v) cout << x << " ";
		cout << endl;
	}
}

