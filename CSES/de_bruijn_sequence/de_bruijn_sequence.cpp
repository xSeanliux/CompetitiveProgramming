#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

const int maxN = (1 << 15);
int N;

int adj[maxN][2];
string ans = "";
stack<int> stk;

int main(){
	cin >> N;
	if(N == 1){
		cout << "10\n";
		return 0;
	}
	for(int i = 0; i < (1 << (N - 1)); i++){
		adj[i][0] = ((i & ((1 << (N - 2)) - 1)) << 1);	
		adj[i][1] = ((i & ((1 << (N - 2)) - 1)) << 1) | 1;	
		//cout << "adj[" << i << "][0] = " << adj[i][0] << endl;
		//cout << "adj[" << i << "][1] = " << adj[i][1] << endl;
	}
	for(int i = 0; i < N - 2; i++) ans += '0';
	stk.push(0);
	string news = "";
	while(stk.size()){
		int i = stk.top();
		if(adj[i][0] == -1 && adj[i][1] == -1){
			news += (char)((i & 1) + '0');
			//cout << i << " ";
			stk.pop();
			continue;
		}
		if(adj[i][0] != -1){
			stk.push(adj[i][0]);
			adj[i][0] = -1;
		} else if(adj[i][1] != -1){
			stk.push(adj[i][1]);
			adj[i][1] = -1;
		}
	}
	reverse(news.begin(), news.end());
	ans = ans + news;
	cout << ans << endl;
}
