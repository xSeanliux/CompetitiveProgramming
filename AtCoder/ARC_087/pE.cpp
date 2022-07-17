#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int maxN = 1e3 + 326;
int sg[maxN], has[maxN], N, SG, L;
string s;

//sg = lowbit
//
//
inline int lowbit(int x){
	return x & -x;
}

struct Node{
	Node *chi[2];
	Node(Node *l = NULL, Node *r = NULL) {
		chi[0] = l;
		chi[1] = r;
	}
} *root = new Node();

struct Trie{
	void ins(string s){
		Node *cur = root;
		for(char c : s){
			if(!cur->chi[c - '0']) cur->chi[c - '0'] = new Node();
			cur = cur->chi[c - '0'];
		}
	}
	void dfs(Node *n = root, int dep = 0){
		//if(!dep) cout << "Now at root" << endl;
		if(n->chi[0] && n->chi[1]){
			//cout << "going 0" << endl;
			dfs(n->chi[0], dep + 1);
			//cout << "going 1" << endl;
			dfs(n->chi[1], dep + 1);
		} else if(n->chi[0]){
			//cout << "Updating " << L - dep << endl;
			//cout << "going 0" << endl;
			dfs(n->chi[0], dep + 1);
			SG ^= lowbit(L - dep);
		} else if(n->chi[1]){
			//cout << "Updating " << L - dep << endl;
			//cout << "going 1" << endl;
			dfs(n->chi[1], dep + 1);
			SG ^= lowbit(L - dep);
		}
	}
} trie;

signed main(){
	cin >> N >> L;
	while(N--){
		cin >> s;
		trie.ins(s);
	}
	trie.dfs();
	if(SG == 0){
		cout << "Bob" << endl;
	} else {
		cout << "Alice" << endl;
	}
}
