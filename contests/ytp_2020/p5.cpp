#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int maxN = 30;
vector<char> adj[maxN + 'Z'];
bool vis[maxN + 'Z'];

string que, conn, cur;

void dfs(char now){
	vis[now] = true;
	for(char c : adj[now]){
		if(!vis[c]) dfs(c);
	}
}

int main(){
	cin >> conn >> que;
	char now = 'A';
	for(char ch : conn){
		if(ch == ','){
			for(char x : cur){
				adj[(int)x].push_back(now);
			}
			cur = "";
			now++;
		} else {
			cur += ch;
		}
	}
	for(char x : cur){
		adj[x].push_back(now);
	}
	for(char src : que){
		for(char c = 'A'; c <= 'Z'; c++) vis[c] = false;
		dfs(src);
		for(char c = 'A'; c <= 'Z'; c++) if(vis[c]) cout << c;
		cout << endl;
	}

}
