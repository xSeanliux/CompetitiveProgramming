#include <iostream>
#include <sstream>
#define int long long int
using namespace std;

const int maxN = (1 << 20) + 326;
string s;

int N;

struct Node{
	Node *chi[2];
	int dp[101][101];
	Node(): dp(){
		for(int i = 0; i <= 100; i++) for(int j = 0; j <= 100; j++) dp[i][j] = 0;
	}
} *root;

inline void insert(string s){
	Node *cur = root;
	for(char c : s){
		if(!cur->chi[c - '0']) cur->chi[c - '0'] = new Node();
		cur = cur->chi[c - '0'];
	}
}

inline void rundp(Node *&n){
	if(n->chi[0]){
		rundp(n->chi[0]);
		rundp(n->chi[1]);
		for(int i = 1; i <= 101; i++){
			for(int m = 1; m <= i; m++){
				for(int j = i; j <= 101 && i + j <= 100; j++){
					n->dp[i + j][m] += n->chi[0]->dp[i][m] * n->chi[1]->dp[j][i];
				}
			}
		}
		for(int i = 1; i <= 100; i++){
			for(int j = 99; j >= 0; j--) n->dp[i][j] += n->dp[i][j + 1];
		}
	} else {
		for(int i = 1; i <= 100; i++){
			n->dp[i][i] = 1;
			for(int j = 99; j >= 0; j--) n->dp[i][j] += n->dp[i][j + 1];
		}
	}
}

inline void solve(){
	root = new Node();
	stringstream ss;
	ss << s;
	string cur;
	ss >> N;
	for(int i = 0; i < N; i++){
		ss >> cur;
		insert(cur);
	}
	rundp(root);
	int ans = 0;
	for(int i =1; i<= 100; i++) ans += root->dp[100][i];
	cout << ans << endl;
}

signed main(){
	int jizz = 0;
	for(int a = 1; a <= 100; a++){
		for(int b = 1; b <= 100; b++){
			if(a + b > 96) break;
			for(int c = 1; c <= 100; c++){
				if(a + b + c > 98) break;
				for(int d = 1; d <= 100; d++){
					if(a + b + c > 99) break;
					for(int e = 1; e <= 100; e++){
						if(a + b + c + d + e > 100) break;
						if(b <= c && c <= a && a <= b + c && b + c <= d && d <= e && a + b + c + d + e == 100) jizz++;
					}
				}
			}
		}
	}
	cout << jizz << endl;
	while(getline(cin, s)){
		if(s == "0") return 0;
		solve();
	}
}
