#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int t;
string s;

/*
 *  -1 (
 *  -2 )
 *  -3 +
 *  -4 -
 *  -5 *
 */

inline int add(int a, int b){
	return (a + b + 700) % 7;
}

inline int sub(int a, int b){
	return (a - b + 700) % 7;
}

int nopar(vector<int> &v){ 
	if(!v.size()) return 0;
	deque<int> dq = deque<int>();
	int r = 0;
	//assume t = 1
	if(t == 1){
		for(int x : v){
			if(dq.size() && dq.back() == -5){
				dq.pop_back();
				int k = dq.back(); dq.pop_back();
				dq.push_back(x * k % 7);
			} else dq.push_back(x);
		}	
		/*
		for(int x : dq) cout << x << " ";
		cout << endl;
		*/
		r = dq.front();
		dq.pop_front();
		while(dq.size()){
			int op = dq.front(); dq.pop_front();
			int num = dq.front(); dq.pop_front();
			if(op == -3) r = add(r, num);
			else r = sub(r, num);
		}
		return r;
	} else {
		reverse(v.begin(), v.end());
		for(int x : v){ //do -
			if(dq.size() && dq.back() == -4){
				dq.pop_back();
				int k = dq.back(); dq.pop_back();
				dq.push_back(sub(x, k));
			} else dq.push_back(x);
		}
		/*
		cout << "After - " << endl;
		for(int x : dq) cout << x << " ";
		cout << endl;
		*/
		deque<int> dq2 = deque<int>();
		for(int x : dq){
			if(dq2.size() && dq2.back() == -3){
				dq2.pop_back();
				int k = dq2.back(); dq2.pop_back();
				dq2.push_back(add(x, k));
			} else dq2.push_back(x);
		}
		swap(dq, dq2);
		/*
		cout << "After + " << endl;
		for(int x : dq) cout << x << " ";
		cout << endl;
		*/
		deque<int>().swap(dq2);
		r = 1;
		for(int i = 0; i < dq.size(); i += 2) r = r * dq[i] % 7;
		return r;
	}
}

int main(){
	cin >> t >> s;
	vector<int> vec;
	for(char c : s){
		if(c == '(') vec.push_back(-1);
		else if(c == ')') vec.push_back(-2);
		else if(c == '+') vec.push_back(-3);
		else if(c == '-') vec.push_back(-4);
		else if(c == '*') vec.push_back(-5);
		else vec.push_back((c - '0') % 7);
	}
	deque<int> dq = deque<int>();
	vector<int> tmp;
	for(int x : vec){
		if(x == -2){
			vector<int>().swap(tmp);
			while(dq.size() && dq.back() != -1){
				tmp.push_back(dq.back());
				dq.pop_back();
			}
			reverse(tmp.begin(), tmp.end());
			dq.pop_back();
			dq.push_back(nopar(tmp));
		} else dq.push_back(x);
	}
	vector<int>().swap(tmp);
	for(int x : dq) tmp.push_back(x);
	cout << nopar(tmp) << endl;
}

