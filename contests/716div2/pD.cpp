#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 326, bS = 500;

struct Que{
	int l, r, id;
	Que(){}
	Que(int l, int r, int id): l(l), r(r), id(id){}
	const bool operator<(const Que &q) const {
		return ((l / bS == q.l / bS) ? r < q.r : l / bS < q.l / bS);
	}
} ques[maxN], q;

int N, Q, l, r, ans[maxN], frq[maxN], cnt[maxN], most, arr[maxN];

inline void addNum(int x){
	cnt[frq[x]]--;
	frq[x]++;
	if(frq[x] > most) most = frq[x];
	cnt[frq[x]]++;
}

inline void remNum(int x){
	cnt[frq[x]]--;
	if(!cnt[most]) most--;	
	frq[x]--;
	cnt[frq[x]]++;
}


int main(){
	ericxiao;
	cin >> N >> Q;
	cnt[0] = N;	
	for(int i = 1; i <= N; i++) cin >> arr[i];
	for(int i = 0; i < Q; i++){
		cin >> l >> r;
		ques[i] = Que(l, r, i);
	}
	sort(ques, ques + Q);
	addNum(arr[1]);
	int L = 1, R = 1;
	for(int i = 0; i < Q; i++){
		q = ques[i];
		while(L > q.l) addNum(arr[--L]);
		while(R < q.r) addNum(arr[++R]);
		while(L < q.l) remNum(arr[L++]);
		while(R > q.r) remNum(arr[R--]);
		int a = 0;
		if(most > (q.r - q.l + 1 + 1) / 2){
			int residue = q.r - q.l + 1 - most;	
			a = max(0, most - 2 * residue);
			int nmost = min(most, 2 * residue);
			a += nmost - residue;
		} else {
			a = 1;
		}
		ans[q.id] = a;
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << "\n";
}
