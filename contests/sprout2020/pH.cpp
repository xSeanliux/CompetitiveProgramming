#include <iostream>
#include <string.h>
#include <stack>
#define int long long int
using namespace std;

const int maxN = 5e5 + 226;
int top = 0, pos = 0;
stack<int> A;
string prog = "", s;
int getNum(){
	char c;
	int sgn = (prog[++pos] == 'S' ? 1 : -1), num = 0;	
	while(true){
		c = prog[++pos];
		if(c == 'L'){
			return sgn * num;
		}
		num = num * 2 + (c == 'T');
	}
}
/*
SS T TSTS L // append -1010 (”-10” in binary) to A
TLST // output -10 and pop it, now A is empty
SS S TTSSTT L // append +110011 (”+51” in binary) to A
TLSS // output ’3’ and pop it, now A is empty
SS T TS L // append -10 (”-2” in binary) to A
SS T TST L // append -101 (”-5” in binary) to A
TSSL // pop the last 2 items of A, multiply them, and append to A
TLSS // output ’\n’ and pop it, now A is empty
LLL // the end of the program
*/
signed main(){
	while(getline(cin, s)){
		for(char c : s){
			if(c == ' ') prog += 'S';
			if(c == '\t') prog += 'T';
		}
		prog += 'L';
	}
	//cout << prog<< endl;
	char c;
	string cur = "";
	for(; pos < prog.length(); pos++){
		//cout << "pos = " << pos << endl;
		cur += prog[pos];
		if(cur == "SS"){
			A.push(getNum());
			//cout << "Pushing " << A[top - 1] << endl;
			cur = "";
		} else if(cur == "SLL"){
			//cout << "Popping" << endl;
			A.pop();
			cur = "";
		} else if(cur == "TSSS"){
			//cout << "Sum" << endl;
			int a = A.top(); A.pop();
			int b = A.top(); A.pop();
			A.push(a + b);
			cur = "";
		} else if(cur == "TSSL"){
			//cout << "Mult" << endl;
			int a = A.top(); A.pop();
			int b = A.top(); A.pop();
			A.push(a * b);
			cur = "";
		} else if(cur == "TLSS"){
			//cout << "OutChar" << endl;
			cout << (char)(A.top());	
			A.pop();
			cur = "";
		} else if(cur == "TLST"){
			//cout << "Outnum" << endl;
			int k = A.top();
			A.pop();
			if(k == 0){
				cout << 0;
			} else if(k > 0){
				cout << k;
			} else {
				cout << k;
			}
			cur = "";
		} else if(cur == "LLL"){
			return 0;
		}
	}
}
