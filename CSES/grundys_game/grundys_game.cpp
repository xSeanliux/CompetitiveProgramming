#include <iostream>
#include <set>
using namespace std;

const int maxN = 1e4 + 326, maxC = 3e3;
int T, N, sg[maxN];
bool has[maxN];

int main(){
	sg[1] = sg[2] = 0;
	for(int i = 3; i < maxN; i++){
		fill(has, has + 300, 0);
		for(int j = 1; j < i - j; j++){
			has[sg[j] ^ sg[i - j]] = 1;
		}
		for(int j = 0; j < maxC; j++) if(!has[j]){
			sg[i] = j;
			break;
		}
	}
	int cnt = 0;
	/*
	for(int i = 0; i < maxN; i++) if(!sg[i]){
		cout << i << " ";
		cnt++;
	}
	cout << endl;
	cout << "cnt = " << cnt <<endl;
	*/
	cin >> T;
	while(T--){
		cin >> N;
		cout << ((N > maxN || sg[N]) ? "first" : "second") << endl;
	}
}
