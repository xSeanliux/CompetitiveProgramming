#include <iostream>
#include <algorithm>
#include <string.h>
#include <bitset>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 100 + 326;
int N, L, Q, k;
string arr[maxN], toxor = "", Z = "", res;

bool isOn[maxN];

struct Node{
	Node *chi[2];
	int sz;
	Node(): sz(0){
		chi[0] = chi[1] = NULL;
	}
	inline void pull(){
		sz = (chi[0] ? chi[0]->sz : 0) + (chi[1] ? chi[1]->sz : 0);
	}
} *root = new Node();

inline int Sz(Node *n){
	return n ? n->sz : 0;
}

inline void add(Node *&n, string &s, int id = 0){
	if(id == L){
		n->sz++;
		return;
	}
	if(!(n->chi[s[id] - '0'])) n->chi[s[id] - '0'] = new Node();
	add(n->chi[s[id] - '0'], s, id + 1);
	n->pull();
}

inline void rem(Node *&n, string &s, int id = 0){
	bool f;
	if(id == L - 1) n->sz--;
	else rem(n->chi[s[id] - '0'], s, id + 1);
	if(id < L - 1) n->pull();
	if(!n->sz) delete n;
}

inline void find(){
	int k = N / 2 + 1; 
	Node *cur = root;
	for(int i = 0; i < L; i++){
		if(Sz(cur->chi[toxor[i] - '0']) >= k){
			cur = cur->chi[toxor[i] - '0'];	
			res += '0';
		} else {
			k -= Sz(cur->chi[toxor[i] - '0']);
			cur = cur->chi[(toxor[i] - '0') ^ 1];
			res += '1';
		}
	}
}

void disp(Node *r = root, int dep = 0){
	if(!r) return;
	cout << "sz = " << r->sz << endl;
	if(r->chi[0]){
	for(int i = 0; i < dep; i++) cout << '\t';	
	cout << "0: " << endl; disp(r->chi[0], dep + 1);}
	if(r->chi[1]){
	for(int i = 0; i < dep; i++) cout << '\t';	
	cout << "1: " << endl; disp(r->chi[1], dep + 1);}
}

int main(){
	cin >> N >> L >> Q;
	for(int i = 0; i < L; i++) toxor += '0';
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		add(root, arr[i]);
	}
	while(Q--){
		cin >> k;
		rem(root, arr[k]);
		add(root, toxor);
		swap(toxor, arr[k]);
		res = "";
		find();
		cout << res << endl;
	}
}
