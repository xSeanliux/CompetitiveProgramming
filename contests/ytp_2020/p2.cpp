#include <iostream> 
using namespace std;

const int maxN = 1e5 + 226;

int N, M, t;
int slip[maxN], roll[maxN];

int main(){
	cin >> N >> M >> t;
	for(int i = 0; i < N; i++) cin >> slip[i];
	for(int i = 0; i < t; i++) cin >> roll[i];
	int l = 0, r = N - 1, pos = 0, round;
	bool jizz = false;
	for(round = 0; round < t; round++){
		//sim
		pos += roll[round];
		pos += slip[pos];
		if(pos == r){
			cout << "Winner Penguin" << endl;
			jizz = true;
			break;
		}
		l += M;
		r -= M;
		if(!(l <= pos && pos <= r && l <= r)){
			cout << "Dumb Dumb Penguin" << endl;
			jizz = true;
			break;
		}
	}
	if(!jizz) cout << "Winner Penguin" << endl;
	cout << "Survived " << round + 1 << " rounds" << endl;
}
