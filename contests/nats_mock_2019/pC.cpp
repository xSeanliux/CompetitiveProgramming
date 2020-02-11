#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e5 + 10, maxLog = 30;

int N, Q, l, r, c, pre[maxN], nearGood[maxN], ans[maxN];

struct Seg{
	int l, r, c;
	Seg(int l, int r, int c): l(l), r(r), c(c){}
	bool operator<(Seg s) const {
		return r < s.r;
	}
};

vector<Seg> segs, newsegs;

int main(){
	ericxiao;
	cin >> N >> Q;	
	for(int i = 0; i < Q; i++){
		cin >> l >> r >> c;
		segs.emplace_back(l, r, c);
	}
	sort(segs.begin(), segs.end());
	for(int b = 0; b < maxLog; b++){
		vector<Seg>().swap(newsegs);
		fill(pre, pre + N + 1, 0);
		for(Seg s : segs){
			if((s.c & (1 << b)) > 0){
				newsegs.emplace_back(s.l, s.r, (s.c & (1 << b)) > 0);
			} else { 
				pre[s.l]++;
				pre[s.r + 1]--;
			}
		}
		int cur = -1;
		for(int i = 1; i <= N; i++){
			pre[i] += pre[i - 1];
			if(!pre[i]) cur = i;
			nearGood[i] = cur;
		}
		int addIndex = -1, addnum = 0;
		for(Seg &s : newsegs){
			s.r = nearGood[s.r];
			if(s.l > addIndex || s.r < addIndex){
				addIndex = s.r;
				ans[addIndex] |= (1 << b);
			}
		}			
	}
	for(int i = 1; i <= N; i++) cout << ans[i] << " \n"[i == N];
}
