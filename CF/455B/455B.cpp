#include <iostream>
using namespace std;

const int W = 26;
int N, K;

string s;

struct Node{
	Node *childs[W];
	bool wl;
	Node(){
		for(int i = 0; i < W; i++) childs[i] = NULL;
	}
} *root;

void insert(string s){
	Node *cur = root;
	for(char c : s){
		if(!cur->childs[c - 'a']){
			cur->childs[c - 'a'] = new Node();
		}
		cur = cur->childs[c - 'a'];
	}
}

inline void dfs(Node *cur, bool def){
	cur->wl = false;
	int c = 0;
	for(int i = 0; i < W; i++){
		if(cur->childs[i]){
			c++;
			dfs(cur->childs[i], def);
			if(!cur->childs[i]->wl){
				cur->wl = true;
			}
		}
	}
	//cout << "My: " << cur->wl << endl;
	if(!c) cur->wl = def;
}

bool rf, rt;

int main(){
	root = new Node();
	cin >> N >> K;	
	while(N--){
		cin >> s;
		insert(s);
	}
	dfs(root, false);
	rf = root->wl; //does the rfst person have a strategy to always win
	dfs(root, true);
	rt = root->wl; //does the rfst person have a strategy to always lose
	//cout << "rf = " << rf << ", rt = " << rt << endl;
	if(!rf){
		cout << "Second\n";	
		return 0;
	}
	if(rt){
		cout << "First\n";				
	} else {
		cout << (K % 2 ? "First\n" : "Second\n");
	}
}

