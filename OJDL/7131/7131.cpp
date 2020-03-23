#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int maxNodes = 2e6 + 10;

struct Node{
	int nxt[3] = {0}, endcnt = 0, dp = 0, nxtdp = 0, fail = 0, from;
	Node(){}
} trie[maxNodes];

bool nowUpd[maxNodes], nxtUpd[maxNodes];

int cnt = 2, N, K, w, id[maxNodes];
string s, t;

int newNode(){
	trie[cnt] = Node();
	return cnt++;
}

void insert(string s, int w){
	int cur = 1;
	for(char c : s){
		if(!trie[cur].nxt[id[c]]){
			trie[cur].nxt[id[c]] = newNode();
			trie[trie[cur].nxt[id[c]]].from = cur;
		}
		cur = trie[cur].nxt[id[c]];
	}
	trie[cur].endcnt += w;
}

void getFail(){
	queue<int> que;
	trie[1].fail = 1;
	int cn, q;
	for(int i = 0; i < 3; i++){
        if(!trie[1].nxt[i]) continue;
        trie[trie[1].nxt[i]].fail = 1;
        que.push(trie[1].nxt[i]);
    }
	while(que.size()){
		cn = que.front();
		que.pop();
		for(int i = 0; i < 3; i++){
			if(!trie[cn].nxt[i]) continue;
			q = trie[cn].fail;
			while(q > 1 && !trie[q].nxt[i]) q = trie[q].fail;
			if(trie[q].nxt[i]) q = trie[q].nxt[i];
			trie[trie[cn].nxt[i]].fail = q;
			trie[trie[cn].nxt[i]].endcnt += trie[q].endcnt;
			que.push(trie[cn].nxt[i]);
		}
	}
}

int getAns(int u){
	int r = trie[u].dp;
	for(int i = 0; i < 3; i++){
		if(trie[u].nxt[i]) r = max(r, getAns(trie[u].nxt[i]));
	}
	return r;
}

void disp(int u, int dep){
	for(int i = 0; i < 3; i++){
		if(trie[u].nxt[i]){
            for(int j = 0; j < dep; j++) cout << " ";
            cout << '(' << (char)(i + 'A') << trie[trie[u].nxt[i]].endcnt << "/ID=" << trie[u].nxt[i] << "/DP=" << trie[trie[u].nxt[i]].dp << "/FAIL=" << trie[trie[u].nxt[i]].fail << ")\n";
			disp(trie[u].nxt[i], dep + 1);
		}
	}
}

void updNode(int u, int ind){ //u has already been updated
	//cout << "Updating " << u << " with char " << (char)(i + 'A') << endl;
	int toUpd = u;
	while(toUpd > 1 && !trie[toUpd].nxt[ind]) toUpd = trie[toUpd].fail;
	if(trie[toUpd].nxt[ind]) toUpd = trie[toUpd].nxt[ind];
	nxtUpd[toUpd] = true;
	//cout << "Toupd = " << toUpd << endl;
	trie[toUpd].nxtdp = max(trie[toUpd].nxtdp, trie[u].dp + trie[toUpd].endcnt);
}

int main(){
	cin >> N >> K;
	id['r'] = 0;
	id['g'] = 1;
	id['b'] = 2;
	for(int i = 0; i < K; i++){
		cin >> s >> w;
		insert(s, w);
	}
	cin >> t;
	getFail();
	//disp(1, 0);
	trie[1].dp = 0;
	nowUpd[1] = true;
	for(int i = 0; i < N; i++){
		//cout << "i = " << i << endl;
		if(t[i] == 'x'){
			for(int j = 1; j < cnt; j++){
				if(nowUpd[j]){
					//cout << "JIZZ" << endl;
					updNode(j, 0);
					updNode(j, 1);
					updNode(j, 2);
					//cout << "Updating " << j << endl;
				}
			}
		} else {
			for(int j = 1; j < cnt; j++){
				if(nowUpd[j]){
					updNode(j, id[t[i]]);
					//cout << "Updating with id = " << id[t[i]] << endl;

				}
			}
		}
	    for(int j = 1; j < cnt; j++){
            trie[j].dp = trie[j].nxtdp;
            trie[j].nxtdp = 0;
            nowUpd[j] = nxtUpd[j];
        }
        fill(nxtUpd, nxtUpd + cnt, 0);
        //disp(1, 0);
        //cout << endl;
	}
	cout << getAns(1) << endl;
}
