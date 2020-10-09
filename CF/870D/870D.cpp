#include <iostream>
using namespace std;

const int maxN = 1e4 + 326;
int bx[maxN], px[maxN], N, b[maxN], p[maxN], p2[maxN], cnt = 0, perm[maxN], has[maxN];

/*
 *
 * p = 3 1 2 0
 * b = 3 1 2 0
 * */

int main(){
	cin >> N;	
	for(int i = 0; i < N; i++){
		cout << "? 0 " << i << endl; 
		cin >> bx[i];
	}
	for(int i = 0; i < N; i++){
		cout << "? " << i << " 0" << endl;	
		cin >> px[i];
	}
	for(int pos = 0; pos < N; pos++){ //position of 1
		//b[  0] = pos
		//p[pos] = 0
		fill(p, p + N, -1);
		fill(p2, p2 + N, -1);
		fill(b, b + N, -1);
		b[0] = pos;
		p2[pos] = 0;
		p[pos] = 0;
		for(int i = 0; i < N; i++){
			if(i == pos) continue;
			p[i] = px[i] ^ px[pos];
		}
		for(int i = 1; i < N; i++){
			b[i] = bx[i] ^ bx[0] ^ pos;
			p2[b[i]] = i;
		}
		/*
		cout << "for position " << pos << endl;
		for(int i = 0; i < N; i++) cout << p[i] << " ";
		cout << endl;
		for(int i = 0; i < N; i++) cout << p2[i] << " ";
		cout << endl;
		*/
		fill(has, has + N, 0);
		for(int i = 0; i < N; i++) if(p[i] != -1) has[p[i]]++;
		bool can = true;
		for(int i = 0; i < N; i++){
			if(p[i] == -1 || p2[i] == -1 || p[i] != p2[i] || has[i] != 1){
				can = false;
				break;
			}
		}
		for(int i = 0; i < N; i++){
			if((p[0] ^ b[i]) != bx[i]) can = false;
		}
		for(int i = 0; i < N; i++){
			if((p[i] ^ b[0]) != px[i]) can = false;
		}
		for(int i = 0; i < N; i++){
			if((p[i] ^ p[0]) != (px[i] ^ px[0])) can = false;
			if((b[i] ^ b[0]) != (bx[i] ^ bx[0])) can = false;
		}
		if(can){
			cnt++;
			for(int i = 0; i < N; i++) perm[i] = p[i];
			/*
			cout << "Possible: " << endl;
			for(int i = 0; i < N; i++) cout << p[i] << " ";
			cout << endl;
			*/
		}
	}
	cout << "!" << endl;
	cout << cnt << endl;
	for(int i = 0; i < N; i++) cout << perm[i] << " ";
	cout << endl;
}
